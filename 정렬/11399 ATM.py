T=int(input())

a=input().split(' ')

k=0

g=[]

i=0
while i<len(a):

    g=g+[int(a[i])]

    i=i+1


g.sort()

g.reverse()


i=1

while i<=len(g):
    
    k=k+g[i-1]*i

   

    i=i+1

print(k)
