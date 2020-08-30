#include<stdio.h>
#include<string.h>
#define scan(a) scanf("%d",&a)
#define R(i,a,b,c) for(i=a;i<b;i+=c)
#define RI(i,a,b,c) for(i=a;i>=b;i-=c)
#define min(a,b) (a)<(b)?a:b
#define mx 105
int mem[15001];
int main(){
    int t,n,v,C[105];
    scan(t);
    while(t--){
        int i,j;
        scan(v);
        scan(n);
        R(i,0,n,1){
            scan(C[i]);
        }
        R(i,0,15001,1) mem[i]=mx;
        mem[0]=0;
        R(i,0,n,1){
            RI(j,15001-C[i]-1,0,1){
                if(mem[j] < mx)
                    mem[j+C[i]]=min(mem[j+C[i]],mem[j]+1);
            }
        }
        R(i,v,15001,1){
            if(mem[i]!=mx){
                printf("%d %d\n",i,mem[i]);
                break;
            }
        }
    }
}
