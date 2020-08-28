from operator import itemgetter


c=int(input())

bsk=[]

i=0
while i<c:

    strin=input()

    if (strin,len(strin)) not in bsk:

        bsk.append((strin,len(strin)))


    i+=1


bsk.sort(key=itemgetter(0))

bsk.sort(key=itemgetter(1))



i=0
while i<len(bsk):

    print(bsk[i][0])

    i+=1
          
