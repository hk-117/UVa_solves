#include<cstdio>
using namespace std;
int F(int n,int k){
    if(n==1)
        return 0;
    else
        return (F(n-1,k)+k)%n;
}
int main(){
    int i,N;
    while(scanf("%d",&N)==1 && N){
        i=1;
        while(F(N-1,i)+2 != 13){
            i++;
        }
        printf("%d\n",i);
    }
}
