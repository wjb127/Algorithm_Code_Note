#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct stu
{
    char name[20];
    int kor,eng,mat;
    
}student;

student Stu[100000];

bool cmp(const student &a,const student &b)
{
    if(a.kor != b.kor)
        // 감소하는 순서 -> true -> 안 바꿈
        return a.kor > b.kor; 
    
    else if(a.kor == b.kor && a.eng == b.eng && a.mat == b.mat)
    {
        // 사전식 배열일 때(a - b < 0) -> (-) -> true -> 안 바꿈
        if(strcmp(a.name, b.name) < 0)
            return true;
        return false;
    }
    
    else if(a.kor == b.kor && a.eng == b.eng)
        return a.mat > b.mat;
    
    else if(a.kor == b.kor)
        return a.eng < b.eng;



}

int main()
{
    int n;
    scanf("%d", &n);
    
    
    
    for(int i=0;i<n;i++)
    {
        // 각종 정보들 입력받기
        scanf("%s %d %d %d", Stu[i].name, &Stu[i].kor, &Stu[i].eng, &Stu[i].mat);
    }
    
    sort(Stu,Stu+n,cmp);
    
    for(int i=0;i<n;i++)
    {
        // 문자열 출력
         printf("%s\n",Stu[i].name);
    }
    
    return 0;
}
