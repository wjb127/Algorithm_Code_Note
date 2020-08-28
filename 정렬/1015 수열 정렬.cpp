import sys

T=int(input())
i=0

A=[]
C=[]

D=[]
P=[]

j=0


r = lambda: sys.stdin.readline()
   
A = map(int,r().split(' '))


C=list(A)


D=list(C)
D.sort()


i=0

while i<len(C):
    
        
    P.insert(i,D.index(C[i]))

    if i==len(C):
        break

    
    i=i+1

i=0
while i<len(P):

    if P.count(P[i])!=1:

        E=[x for x in range(0,len(P))if P[x]==P[i] ]

        j=0
        
        while j<len(E):
            

            P[E[j]]=P[E[j]]+j

            j=j+1



    i=i+1


i=0
while i<len(C):
    
    print(P[i],end=' ')

    if i==len(C):
        break

    i=i+1
