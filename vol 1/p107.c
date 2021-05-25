#include<stdio.h>
#include<math.h>
#define eps 1e-9
typedef long long int ll;
ll noWork(int N,int pwr){
    ll t=0;
    int i;
    for(i=0;i<pwr;i++){
        t+=pow(N,i);
    }
    return t;
}
int lastHeight(int N,int pwr,int initHeight){
    int i;
    for(i=1;i<=pwr;i++){
        initHeight= initHeight/(N+1);
    }
    if(initHeight==1)
        return 1;
    else
        return 0;
}
ll stHeight(int N,int pwr,ll initHeight){
    ll i,prev=initHeight,nxt;
    for(i=1;i<=pwr;i++){
        nxt = (prev/(N+1));
        initHeight+=(nxt*pow(N,i));
        prev=nxt;
    }
    return initHeight;
}
int main(){
    int a,b;
    double lg;
    while(scanf("%d %d",&a,&b)==2 && (a||b)){
        int N=2,pwr=1;
        if(b==1 && a!=1){
            N=1;
            while(!lastHeight(N,pwr,a)){
                pwr++;
            }
        }
        else{
            while(1){
                lg=log(b)/log(N);
                pwr=lg;
                if(lg-pwr>=0.50)
                    pwr++;
                if(lg-pwr < eps && lastHeight(N,pwr,a)){
                    break;
                }
                N++;
            }
        }
        printf("%lld %lld\n",noWork(N,pwr),stHeight(N,pwr,a));
    }
}
