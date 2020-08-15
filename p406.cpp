#include<bits/stdc++.h>
using namespace std;
int P[200],nPrime,ms[1005];
void sieve(int n){
    int s,i,j;
    s= n;
    nPrime=0;
    memset(ms,0,sizeof(ms));
    ms[0]=1;
    P[nPrime++]=1;
    for(i=2;i<=s;i++){
        if(!ms[i]){
            for(j=i*i;j<=s;j+=i){
                ms[j]=1;
            }
            P[nPrime++]=i;
        }
    }
}

int main(){
    int n,c;
    while(scanf("%d %d",&n,&c)==2){
        int i,j,mid;
        sieve(n);
        printf("%d %d:",n,c);
        if(nPrime%2){
            if(nPrime<2*c-1){
                for(i=0;i<nPrime;i++){
                    printf(" %d",P[i]);
                }
                putchar('\n');
            }
            else{
                mid= nPrime/2;
                c=2*c-1;
                for(i=mid-c/2;i<=mid+c/2;i++){
                    printf(" %d",P[i]);
                }
                putchar('\n');
            }
        }
        else{
            if(nPrime<2*c){
                for(i=0;i<nPrime;i++){
                    printf(" %d",P[i]);
                }
                putchar('\n');
            }
            else{
                mid = nPrime/2;
                for(i=mid-c;i<mid+c;i++){
                    printf(" %d",P[i]);
                }
                putchar('\n');
            }
        }
        putchar('\n');
    }
}
