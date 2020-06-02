#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int x,cs=0;
    scanf("%d",&x);
    while(x--){
        cs++;
        int r,c,n,m;
        scanf("%d %d %d %d",&r,&c,&m,&n);
        char buf[c+1];
        map<char,int> freqs;
        R(i,0,r,1){
            scanf("%s",buf);
            R(j,0,c,1){
                freqs[buf[j]]+=1;
            }
        }
        int mx=INT_MIN;
        for(auto it=freqs.begin();it!=freqs.end();it++){
            mx= mx> it->second ? mx:it->second;
        }
        int sz=0;
        for(auto it=freqs.begin();it!=freqs.end();it++){
            if(it->second ==mx){
                sz+=mx*m;
            }
            else{
                sz+= it->second *n;
            }
        }
        printf("Case %d: %d\n",cs,sz);
    }
}
