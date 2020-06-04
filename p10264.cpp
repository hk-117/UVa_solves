#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int dim;
    while(cin>>dim){
        int corners= (1<<dim);
        int potencies[corners],neighbours[corners]={0};
        R(i,0,corners,1){
            cin>> potencies[i];
        }
        R(i,0,corners,1){
            R(j,0,corners,1){
                int t= i^j;
                if( (t&(t-1))==0 && i!=j ){
                    neighbours[i]+=potencies[j];
                }
            }
        }
        int mx=INT_MIN;
        R(i,0,corners,1){
            R(j,0,corners,1){
                int t= i^j;
                if( (t&(t-1))==0 && i!=j){
                    mx= max(mx,neighbours[i]+neighbours[j]);
                }
            }
        }
        cout<<mx<<endl;
    }
}
