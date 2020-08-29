import sys
import math
T=int(input())
i=0

a=[]
b=[]
c=[]

r = lambda: sys.stdin.readline()



while i<T:
    
    
    
    N, M = map(int,r().split())

    a=a+[math.factorial(N)]
    b=b+[math.factorial(M)]
    c=c+[math.factorial(M-N)]

    i=i+1

    
i=0

while i<T:

    
    print(int(b[i]/(a[i]*c[i])))

    i=i+1
