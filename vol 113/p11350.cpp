#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct rati{
    long long a,b;
};
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char path[100];
        rati r,l,h;
        l.a=0,l.b=1;
        h.a=1,h.b=0;
        r.a=(l.a+h.a),r.b=(l.b+h.b);
        scanf("%s",path);
        int len=strlen(path);
        R(i,0,len,1){
            if(path[i]=='R'){
                l=r;
            }
            else if(path[i]=='L'){
                h=r;
            }
            r.a=l.a+h.a;
            r.b=l.b+h.b;
        }
        printf("%lld/%lld\n",r.a,r.b);
    }
}
