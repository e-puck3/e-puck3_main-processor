#!/usr/bin/env python3
import argparse
import progressbar
import serial
import matplotlib.pyplot as plt
import numpy as np
import time
import colour
from colour_demosaicing import demosaicing_CFA_Bayer_bilinear

WIDTH   = 300
HEIGHT  = 180

TOTAL_SAMPLES_TO_READ = (WIDTH * HEIGHT)/2

def parse_args():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("port", help="Serial port")

    return parser.parse_args()


def main():
    args = parse_args()
    conn = serial.Serial(args.port, timeout=1)

    while(1):
        conn.write("dcmi\r\n".encode())
        buf = bytes()
        print("Placing board in acquisition mode... ", end="")
        while not buf.decode().endswith("Done !\r\n"):
            buf = buf + conn.read(1)
        print("done")

        # Then read the whole sample out
        buf = bytes()
        pbar = progressbar.ProgressBar(maxval=TOTAL_SAMPLES_TO_READ).start()
        while len(buf) < 4 * TOTAL_SAMPLES_TO_READ:
            pbar.update(len(buf) / 4)
            buf += conn.read(100)
        pbar.finish()

        print(len(buf))

        image = np.frombuffer(buf, dtype='uint16')
        image = image.reshape((HEIGHT,WIDTH))

        image_rgb = demosaicing_CFA_Bayer_bilinear(image, 'GRBG')

        image_rgb = image_rgb/np.amax(image_rgb)

        plt.imshow(image_rgb)
        plt.pause(0.033)
        plt.close()



if __name__ == '__main__':
    main()
