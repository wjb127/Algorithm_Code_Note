m=input()

st=[]

count=0

cb=0

i=0
while i<len(m):

    if i>=1 and st[len(st)-1]=='(':

        if m[i]==')':

            st[len(st)-1]='*'

            count-=1

            cb+=count

        else:

            st.append(m[i])
            count+=1

    elif m[i]=='(':

        st.append(m[i])

        count+=1
    elif i>=1 and st[len(st)-1]!='(' and m[i]==')':

        st.append(m[i])

        count-=1
        cb+=1

    else:

        st.append(m[i])



    i+=1

print(cb)
