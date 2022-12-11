#include<bits/stdc++.h>
#define mx 200099
#define LSOne(S) (S&(-S))
using namespace std;
int ft[mx],A[mx],n;
int rsqOne(int b){
    int sum=0;
    for(;b;b-=LSOne(b))
        sum+=ft[b];
    return sum;
}
int rsqTwo(int a,int b){
    return rsqOne(b)-(a==1 ? 0 : rsqOne(a-1));
}
void adjust(int k,int v){
    for(;k<=n;k+=LSOne(k))
        ft[k]+=(v);
}
int main(){
    int tc=0;
    while(scanf("%d",&n)==1 && n){
        int x,y,i,inp;
        char Dir[5];
        memset(ft,0,sizeof(ft));
        memset(A,0,sizeof(A));
        if(tc++)
            putchar('\n');
        for(i=1;i<=n;i++){
            scanf("%d",&inp);
            A[i-1]=inp;
            adjust(i,inp);
        }
        printf("Case %d:\n",tc);
        getchar();
        while(scanf("%s",Dir)==1 && strcmp(Dir,"END")){
            scanf("%d %d",&x,&y);
            if(Dir[0]=='M'){
                printf("%d\n",rsqTwo(x,y));
            }
            else{
                adjust(x,y-A[x-1]);
                A[x-1]=y;
            }
        }
    }
}
