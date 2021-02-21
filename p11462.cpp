#include<cstdio>
#include<cstring>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define RI(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
int main(){
    int N,L=1,R=99;
    while(scanf("%d",&N)==1 && N){
        int A[N],O[N],C[R-L+1];
        memset(C,0,sizeof C);
        R(i,0,N,1){
            scanf("%d",&A[i]);
            C[A[i]-L]++;
        }
        R(i,1,(R-L+1),1){
            C[i]+=C[i-1];
        }
        RI(i,N-1,0,1){
            O[C[A[i]-L]-1]=A[i];
            --C[A[i]-L];
        }
        printf("%d",O[0]);
        R(i,1,N,1){
            printf(" %d",O[i]);
        }
        printf("\n");
    }
}
