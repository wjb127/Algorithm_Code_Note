import sys

T=int(input())
i=0
a=[]
d=0



r = lambda: sys.stdin.readline()

 
a = map(int,r().split(' '))
b = map(int,r().split(' '))


e=list(a)
e.sort()
c=list(b)
c.sort()
c.reverse()

for i in range(0,T):

    d=d+e[i]*c[i]

print(d)
   
