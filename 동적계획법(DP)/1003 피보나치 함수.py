T=int(input())


i=2

a=[]


b=[0,1]

i=0
while i<T:
    
    c=int(input())

    a=a+[c]

    i=i+1

i=2
while i<=max(a):

    b=b+[b[i-1]+b[i-2]]

    i=i+1



i=0

while i<len(a):

    

    if a[i]==0:

        print(1,0)
        

    else:

        print(b[a[i]-1],b[a[i]])
        


    i=i+1

