import math

coins = [0.25, 0.10, 0.05, 0.01]

#receiving cash
while True:
    try:
        owed = float(input("change: "))
        if(owed < 0):
            continue
        else:
            break
    except:
        continue

num_coins = 0



#can possibly be simplified with a function if you want to optimise... im lazy
while(owed > 0):

    if(owed/0.25 >= 1):
        temp = math.floor(owed/0.25)
        num_coins += temp
        owed -= temp*0.25
        owed = round(owed, 2)
        continue

    elif(owed/0.10 >= 1):
        temp = math.floor(owed/0.10)
        num_coins += temp
        owed -= temp*0.10
        owed = round(owed, 2)
        continue

    elif(owed/0.05 >= 1):
        temp = math.floor(owed/0.05)
        num_coins += temp
        owed -= temp*0.05
        owed = round(owed, 2)
        continue

    elif(owed/0.01 >= 1):
        temp = math.floor(owed/0.01)
        num_coins += temp
        owed -= temp*0.01
        owed = round(owed, 2)
        continue

def change()


print(num_coins)