#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        tc++;
        printf("Case %d: ",tc);
        double d,v,u;
        scanf("%lf %lf %lf",&d,&v,&u);
        if(u<=v){
            puts("can't determine");
            continue;
        }
        double t1= d/sqrt(u*u-v*v);
        double t2= d/u;
        if((t1-t2)<=0)
            puts("can't determine");
        else
            printf("%.3lf\n",t1-t2);
    }
}
