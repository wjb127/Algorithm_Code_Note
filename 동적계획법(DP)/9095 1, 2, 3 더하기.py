import sys
import math

T=int(input())
i=0

x=[]
d=0

r = lambda: sys.stdin.readline()

while i<T:
    
    
    n = int(input())

    b=0
    
    d=0

    while b<=n//2:

        c=0

        while c<=(n-2*b)//3:

            if n-2*b-3*c<0:

                break

            
            

            d=d+math.factorial(n-b-2*c)/(math.factorial(b)*math.factorial(c)*math.factorial(n-2*b-3*c))

            c=c+1
         

        b=b+1
     

        

    x=x+[d]

    i=i+1

i=0
while i<T:

    print(int(x[i]))

    i=i+1
    
