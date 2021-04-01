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
    print(" " * (height - i - 1) + "#" * (i + 1), end = "")
    print("  " + "#" * (i + 1))
    
    
