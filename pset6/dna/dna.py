import csv
from sys import argv

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

people = {}
#open csv file
with open(argv[1]) as file:
    #note wanted STRs
    STRlist = file.readline().strip().split(',')[1:]
    
    #make dict of persons and STR count
    for line in file:
        cur = line.strip().split(',')
        people[cur[0]] = [int(x) for x in cur[1:]]
    

txtSTR = []
#open txt file and count STRs
with open(argv[2]) as file:
    line = file.readline().strip()
    
    #for each STR
    for i in range(len(STRlist)):
        curSTR = STRlist[i]
        STRlen = len(STRlist[i])                   
        max_rep = 0                                
        
        #iterate over line for STR matches
        for i in range(len(line)):
            cur_rep = 0
            index = i
            while(True):
                read = line[index:(index + STRlen)]         #read a chunk of equal length to wanted STR
                if read == curSTR:                          #if read chunk matches, loop read
                    cur_rep += 1
                    index += STRlen                             #moves index forward to read next chunk
                    continue
                else:
                    break
                
            if cur_rep > max_rep:
                max_rep = cur_rep
                
        #make list of STR counts in txt
        txtSTR.append(max_rep)

        
for name in people:
    if people[name] == txtSTR:
        print(name)
        exit(0)
        
print("No match")
exit(2)
