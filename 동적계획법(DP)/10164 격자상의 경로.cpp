import math

a=input().split(' ')


sero=int(a[0])

garo=int(a[1])

wichi=int(a[2])

key=True

if wichi==0:

    key=False

if wichi%garo==0 :

    if wichi<garo:
        
        x=wichi-1

    else:

        x=garo-1
else:
    x=wichi%(garo)-1#####???:??
    
if wichi%garo==0:
    if wichi<=garo==0:
        y=0
    else:
        y=wichi//garo-1
else:
    
    y=(wichi)//(garo)








if key:
    z=math.factorial(x+y)/(math.factorial(x)*math.factorial(y))

    w=math.factorial(garo-1-x+sero-1-y)/(math.factorial(garo-1-x)*math.factorial(sero-1-y))
    q=z*w
    print(int(q))
else:
    print(int(math.factorial(garo+sero-2)/(math.factorial(garo-1)*math.factorial(sero-1))))
