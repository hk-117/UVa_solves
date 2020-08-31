#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
#define scan(a) scanf("%d",&a)
#define R(i,a,b,c) for(i=a;i<b;i+=c)
using namespace std;
int main(){
    int n,A[101][101],mx,cur,i,j,k;
    scan(n);
    R(i,0,n,1){
        R(j,0,n,1){
            scan(A[i][j]);
            if(j>0)
                A[i][j]+= A[i][j-1];
        }
    }
    mx= -127*100*100;
    R(i,0,n,1){
        R(j,i,n,1){
            cur=0;
            R(k,0,n,1){
                if(i>0)
                    cur += A[k][j]- A[k][i-1];
                else
                    cur += A[k][j];
                if(cur <0)
                    cur=0;
                mx= max(mx,cur);
            }
        }
    }
    printf("%d\n",mx);
}
