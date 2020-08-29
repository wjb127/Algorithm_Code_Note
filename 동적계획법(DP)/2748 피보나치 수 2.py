b=[0,1]


c=int(input())



i=2
while i<=c:

    b=b+[b[i-1]+b[i-2]]

    i=i+1




print(b[c])
