#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int basek,k,n,dist;
    while(scanf("%d",&k)==1){
        n= (-1+(int)sqrt(1+8*k))/2;
        basek= (n*(n+1))/2;
        dist=k-basek;
        printf("TERM %d IS ",k);
        if(n%2==0){
            if(dist==0)
                printf("%d/%d\n",n,1);
            else{
                dist--;
                printf("%d/%d\n",n+1-dist,1+dist);
            }
        }
        else{
            if(dist==0)
                printf("%d/%d\n",1,n);
            else{
                dist--;
                printf("%d/%d\n",1+dist,n+1-dist);
            }
        }
    }
}
