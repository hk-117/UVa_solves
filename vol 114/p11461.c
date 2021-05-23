#include<stdio.h>
int main(){
    int R[320],MX=0,a,b,i;
    for(MX=0;MX*MX<100005;MX++){
        R[MX]=MX*MX;
    }
    while(scanf("%d %d",&a,&b)==2 && (a||b)){
        int cnt=0;
        for(i=1;i<MX && R[i]<=b;i++){
            if(R[i]>=a && R[i]<=b)
                cnt++;
        }
        printf("%d\n",cnt);
    }
}
