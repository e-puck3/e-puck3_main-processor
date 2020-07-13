#!/usr/bin/env python3
"""
Reads sounds from the F7 discovery kit microphone
"""
import argparse
import progressbar
import serial
import wave
import struct


def parse_args():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("port", help="Serial port")
    parser.add_argument("output", help="WAV file for output")
    parser.add_argument(
        "--length",
        "-l",
        help="Buffer length (44.1k by default)",
        type=int,
        default=44100)
    parser.add_argument(
        "-b",
        "--baudrate",
        type=int,
        default=921600,
        help="Baudrate, default=921600")

    parser.add_argument("--mic",help="Mic to use mic1|mic2|mic3|mic4")

    parser.add_argument(
        "--gain",
        type=float,
        help="Manual gain for the signal (default is auto)")

    return parser.parse_args()


def main():
    args = parse_args()
    conn = serial.Serial(args.port, args.baudrate)

    # First place the board in dfsdm acquisition mode
    if args.mic == 'mic1':
        conn.write("dfsdm_usb mic1\r\n".encode())
    elif args.mic == 'mic2':
        conn.write("dfsdm_usb mic2\r\n".encode())
    elif args.mic == 'mic3':
        conn.write("dfsdm_usb mic3\r\n".encode())
    else:
        conn.write("dfsdm_usb mic4\r\n".encode())
    buf = bytes()
    print("Placing board in acquisition mode... ", end="")
    while not buf.decode().endswith("Done !\r\n"):
        buf = buf + conn.read(1)
    print("done")

    # file = open(args.port,'rb')
    # Then read the whole sample out
    buf = bytes()
    pbar = progressbar.ProgressBar(maxval=args.length).start()
    while len(buf) < 4 * args.length:
        pbar.update(len(buf) / 4)
        buf += conn.read(100)
    pbar.finish()

    # Unpack the buffer (sent as a 32 bit integers)
    data = struct.unpack('<' + 'i' * args.length, buf)

    # Compute the gain to maximize the dynamic range in the WAV file
    if args.gain:
        gain = args.gain
    else:
        gain = ((2**31) - 1) / max(abs(s) for s in data)

    print('gain = ', gain)

    # Write the WAV file
    with wave.open(args.output, 'wb') as f:
        f.setnchannels(1)
        f.setsampwidth(4)
        f.setframerate(44.1e3)
        print("Writing WAV file")
        bar = progressbar.ProgressBar()
        for d in bar(data):
            f.writeframes(struct.pack('i', int(d * gain)))

    print("The board is still capturing data, please"
          "reset it by pressing the black button.")


if __name__ == '__main__':
    main()
