t=int(input())

o=t


a=300
b=60
c=10

inte=True

if t%c!=0:

    inte=False


i=0
while inte and i<=(o//a) :

    
    if t<a:
        break
    t=t-a
    
    i+=1

j=0
while inte and j<=(o//b):

    
    if t<b:
        break
    t=t-b
    

    j+=1

k=0
while inte and k<=(o//c):

    if t<c:
        break
    t=t-c
    

    k+=1

if inte:
    print(i,j,k)
else:
    print(-1)
