


while True:
    try:
        num = int(input("Number: "))
        break
    except:
        continue

array = []
total = 0

for i in range(-2, -(len(str(num)) + 1), -2):
    initial = (str(num)[i])
    multiplied = int(initial)*2
    split = [int(d) for d in str(multiplied)]
    array.extend(split)

for i in range(-1, -(len(str(num)) + 1), -2):
    temp = (str(num)[i])
    total += int(temp)
    

if((total + sum(array))%10 == 0):

    if(str(num)[0] == '3'):
        print("AMEX")

    elif(str(num)[0] == '5'):
        print("MASTERCARD")

    elif(str(num)[0] == '4'):
        print("VISA")

    else:
        print("INVALID")

else:
    print("INVALID")