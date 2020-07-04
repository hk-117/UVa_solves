#include<bits/stdc++.h>
using namespace std;
double calclen(int v,int vo,int i){
    double res;
    if(v<=vo)
        res=0.0;
    else{
        res= i* 0.3 * sqrt((double)v/(double)i-vo);
    }
    return res;
}
int main(){
    int v,vo;
    while(scanf("%d %d",&v,&vo)==2 && v||vo){
        int res=0;
        double len=0,prevlen=0;
        for(int i=1;i<=v;i++){
            len=calclen(v,vo,i);
            if(fabs(len-prevlen) < 1e-9){
                res=0;
                break;
            }
            if(len>prevlen){
                prevlen=len;
                res= i;
            }
        }
        printf("%d\n",res);
    }
}
