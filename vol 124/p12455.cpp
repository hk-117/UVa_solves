#include<bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int t;
    scan(t);
    while(t--){
        int n,p;
        scan(n);
        scan(p);
        int al[p];
        R(i,0,p,1)
            scan(al[i]);
        int flag=0;
        R(i,0,(1<<p),1){
            int su=0;
            R(j,0,p,1){
                if(i & (1<<j)){
                    su+=al[j];
                }
            }
            if(su==n){
                flag=1;
                break;
            }
        }
        if(flag){
            puts("YES");
        }
        else
            puts("NO");
    }
    return 0;
}
