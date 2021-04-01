#completed

#with cs50 lib
from cs50 import get_int

while True:
    height = get_int("height: ")
    if 1 <= height <= 8:
        break

for i in range(int(height)):
    print(" " * (height - i - 1) + "#" * (i + 1))





#without cs50 library
while True:
    try:
        height = int(input("height: "))
        if(height > 8 or height < 1):
            continue
        else:
            break
    except:
        continue

for i in range(int(height)):
    print(" " * (height - i - 1) + "#" * (i + 1))
