#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n||m){
        bitset<1000001>mints;
        int a,b,interval;
        bool conflict=false;
        R(i,0,n,1){
            scanf("%d%d",&a,&b);
            if(conflict)
                continue;
            R(j,a,b,1){
                if(mints[j])
                    conflict=true;
                else
                    mints.set(j);
            }
        }
        R(i,0,m,1){
            scanf("%d%d%d",&a,&b,&interval);
            if(conflict)
                continue;
            int rp=0;
            while(rp<1000001 && !conflict){
                for(int j=rp+a;j<rp+b && j<1000001;j++){
                    if(mints[j]){
                            conflict=true;
                    }
                    else
                        mints.set(j);
                }
                rp+=interval;
            }
        }
        if(conflict){
            printf("CONFLICT\n");
        }
        else{
            printf("NO CONFLICT\n");
        }
    }
}
