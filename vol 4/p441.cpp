#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int k,tc=0;
    while(cin>>k,k){
        int ar[k];
        if(tc)
            puts("");
        tc++;
        R(i,0,k,1){
            cin>>ar[i];
        }
        R(a,0,k-5,1){
            R(b,a+1,k-4,1){
                R(c,b+1,k-3,1){
                    R(d,c+1,k-2,1){
                        R(e,d+1,k-1,1){
                            R(f,e+1,k,1){
                                printf("%d %d %d %d %d %d\n",ar[a],ar[b],ar[c],ar[d],ar[e],ar[f]);
                            }
                        }
                    }
                }
            }
        }
    }
}
