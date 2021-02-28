#include<cstdio>
using namespace std;
int main(){
    int N;
    while(scanf("%d",&N)==1){
        int cnt=1,mod=1%N;
        while(mod!=0){
            cnt++;
            mod=(mod*10+1)%N;
        }
        printf("%d\n",cnt);
    }
}
