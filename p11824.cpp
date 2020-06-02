#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        vector<int> L;
        int land;
        while(cin>>land,land){
            L.push_back(land);
        }
        sort(L.begin(),L.end(),greater<int>());
        int total=0;
        R(i,0,L.size(),1){
            total+= 2* pow(L[i],(i+1));
            if(total>5000000){
                break;
            }
        }
        if(total>5000000){
            cout<<"Too expensive\n";
        }
        else{
            cout<<total<<"\n";
        }
    }
}
