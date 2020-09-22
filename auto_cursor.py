"""
usage: auto_cursor.py [-h] -f FILE -d DELAY

Write file content on cursor

optional arguments:
  -h, --help  show this help message and exit
  -f FILE     input file containing the code
  -d DELAY    Delay in sec before writing to the cursor
"""

from argparse import ArgumentParser
import os.path
import pyautogui
import time


def is_valid_file(parser, arg):
    if not os.path.exists(arg):
        parser.error(f"The file {arg} does not exist!")
    else:
        return open(arg, 'r')  # return an open file handle


parser = ArgumentParser(description="Write file content on cursor")

parser.add_argument("-f", dest="filename", required=True,
                    help="input file containing the code", metavar="FILE",
                    type=lambda x: is_valid_file(parser, x))

parser.add_argument("-d", dest="delay", required=True,
                    help="Delay in sec before writing to the cursor", type=int)


args = parser.parse_args()

print(f"Writing to cursor in {args.delay} sec...")
time.sleep(args.delay)

file_content = args.filename.read()
pyautogui.write(file_content)

