#!/usr/bin/env python3
import argparse
import progressbar
import serial
import matplotlib.pyplot as plt
import numpy as np


def parse_args():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("port", help="Serial port")

    return parser.parse_args()


def main():
    args = parse_args()
    conn = serial.Serial(args.port, timeout=1)

    conn.write("dcmi\r\n".encode())
    buf = bytes()
    print("Placing board in acquisition mode... ", end="")
    while not buf.decode().endswith("Done !\r\n"):
        buf = buf + conn.read(1)
    print("done")

    # Then read the whole sample out
    buf = bytes()
    pbar = progressbar.ProgressBar(maxval=9600).start()
    while len(buf) < 4 * 9600:
        pbar.update(len(buf) / 4)
        buf += conn.read(100)
    pbar.finish()

    print(len(buf))

    image = np.frombuffer(buf, dtype='uint16')
    image = image.reshape((120,160))

    plt.imshow(image, cmap="gray")
    plt.show()


if __name__ == '__main__':
    main()
