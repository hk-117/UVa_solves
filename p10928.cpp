#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int p,m=INT_MAX;
        cin>>p;
        vector<int> neighbours;
        string inp;
        cin.ignore();
        R(i,1,p+1,1){
            int nei=0,a;
            getline(cin,inp);
            stringstream ss(inp);
            while(ss>>a){
                nei++;
            }
            neighbours.push_back(nei);
            m= m<nei ? m:nei;
        }
        cin.ignore();
        int j=0;
        R(i,0,neighbours.size(),1){
            if(neighbours[i]==m){
                if(j++)
                    cout<<" ";
                cout<<i+1;
            }
        }
        cout<<endl;
    }
}
