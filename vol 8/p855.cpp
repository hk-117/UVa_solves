#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int st,av,f;
        cin>>st>>av>>f;
        vector<int> streets(f),avenues(f);
        R(i,0,f,1){
            cin>>streets[i]>>avenues[i];
        }
        sort(streets.begin(),streets.end());
        sort(avenues.begin(),avenues.end());
        cout<<"(Street: "<<streets[(f-1)/2]<<", Avenue: "<<avenues[(f-1)/2]<<")"<<endl;
    }
}
