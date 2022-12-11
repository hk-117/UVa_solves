#include<stdio.h>
#define R(i,a,b,c) for(i=a;i<b;i+=c)
#define scan(a) scanf("%d",&a)
int main(){
    int b,tc=0,rating;
    scanf("%d",&b);
    while(b--){
        int i=1,j,prevj=2,previ=1,s,sum=0,ans=0;
        scan(s);
        R(j,0,s-1,1){
            scan(rating);
            sum+=rating;
            if(ans<=sum){
                if(ans==sum){
                    if(prevj-previ < j-i+2){
                        previ=i;
                        prevj=j+2;
                    }
                }
                else{
                    ans=sum;
                    previ=i;
                    prevj=j+2;
                }
            }
            if(sum<0){
                sum=0;
                i=j+2;
            }
        }
        if(ans<=0){
            printf("Route %d has no nice parts\n",++tc);
        }
        else{
            printf("The nicest part of route %d is between stops %d and %d\n",++tc,previ,prevj);
        }
    }
}
