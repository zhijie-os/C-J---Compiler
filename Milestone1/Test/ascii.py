import sys

while 1:
    char = sys.stdin.read(1)
    if not char: 
        break
    print(ord(char))

