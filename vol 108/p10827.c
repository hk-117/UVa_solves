#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
#define scan(a) scanf("%d",&a)
#define R(i,a,b,c) for(i=a;i<b;i+=c)
int main(){
    int n,A[200][200],mx,cur,i,j,k,l,t;
    scan(t);
    while(t--){
        scan(n);
        R(i,0,n,1){
            R(j,0,n,1){
                scan(A[i][j]);
                A[i][j+n]= A[i][j];
                A[i+n][j]= A[i][j];
                A[i+n][j+n]=A[i][j];
            }
        }
        R(i,0,2*n,1){
            R(j,0,2*n,1){
                if(i>0) A[i][j]+=A[i-1][j];
                if(j>0) A[i][j]+=A[i][j-1];
                if(i>0 && j>0) A[i][j]-=A[i-1][j-1];
            }
        }
        mx= -100*75*75*2;
        R(i,0,n,1){
            R(j,0,n,1){
                R(k,i,i+n,1){
                    R(l,j,j+n,1){
                        cur=A[k][l];
                        if(i>0) cur-=A[i-1][l];
                        if(j>0) cur-=A[k][j-1];
                        if(i>0 && j>0) cur+= A[i-1][j-1];
                        mx = max(mx,cur);
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
}
