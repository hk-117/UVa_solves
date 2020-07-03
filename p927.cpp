#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define scan(a) scanf("%d",&a)
#define scan2(a,b) scanf("%lld %lld",&a,&b)
using namespace std;
int main(){
    int tc;
    scan(tc);
    while(tc--){
        int deg;
        scan(deg);
        deg++;
        int coeff[deg];
        R(i,0,deg,1)
            scan(coeff[i]);
        long long d,k;
        scan2(d,k);
        int p=0,n=1;
        for(;;n++){
            int pos=p;
            p += n*d;
            if(pos<k && k<=p)
                break;
        }
        long long an=0,cn=1;
        R(i,0,deg,1){
            an += coeff[i]*cn;
            cn *= n;
        }
        cout<<an<<endl;
    }
}
