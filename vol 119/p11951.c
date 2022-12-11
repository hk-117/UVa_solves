#include<stdio.h>
#define R(i,a,b,c) for(i=a;i<b;i+=c)
#define MX 105
long long A[MX][MX],p,mx,cur;
int main(){
    int n,m,i,j,k,l,t,tc=0,area;
    scanf("%d",&t);
    while(t--){
        tc++;
        scanf("%d %d %lld",&n,&m,&p);
        R(i,0,n,1){
            R(j,0,m,1){
                scanf("%lld",&A[i][j]);
                if(i>0) A[i][j]+=A[i-1][j];
                if(j>0) A[i][j]+=A[i][j-1];
                if(i>0 && j>0) A[i][j] -= A[i-1][j-1];
            }
        }
        area=0;
        mx=0;
        R(i,0,n,1){
            R(j,0,m,1){
                R(k,i,n,1){
                    R(l,j,m,1){
                        cur=A[k][l];
                        if(i>0) cur-=A[i-1][l];
                        if(j>0) cur-=A[k][j-1];
                        if(i>0 && j>0) cur+= A[i-1][j-1];
                        if(cur <= p){
                            if((area <=(k-i+1)*(l-j+1))){
                                if(area==(k-i+1)*(l-j+1)){
                                    mx=mx<cur?mx:cur;
                                }
                                else{
                                    mx=cur;
                                    area=(k-i+1)*(l-j+1);
                                }
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d %lld\n",tc,area,mx);
    }
}
