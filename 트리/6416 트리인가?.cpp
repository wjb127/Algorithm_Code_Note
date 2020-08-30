#include <cstdio>
#include <algorithm> 
#include <vector>
#include <set>
using namespace std; 
bool ok;
set<int> s; 
int a, b, k = 1, sum; 
int main(){
    while(1){ 
		s.clear();  
		sum = 0; 
        while(1){
            scanf("%d %d", &a, &b); 
            if(a == 0 && b == 0)break;
            if(a < 0 && b < 0){
                ok = true; 
                break;
            }   
			s.insert(b), s.insert(a);
			sum++;  
        }  
        //printf("%d %d\n", (int)s.size(), sum);
        if(ok) break; 
        if(sum == 0 || sum + 1 == (int)s.size()) printf("Case %d is a tree.\n", k);
        else printf("Case %d is not a tree.\n", k);
        k++;  
    } 
    return 0; 
}
