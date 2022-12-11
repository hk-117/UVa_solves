#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void chk(vector<string>&taken,vector<string>&avail,bool &fulfilled,int r){
    int tk=0;
    R(i,0,avail.size(),1){
        auto it=find(taken.begin(),taken.end(),avail[i]);
        if(it != taken.end()){
            tk++;
        }
        if(tk==r)
            break;
    }
    if(tk<r)
        fulfilled=false;
}

int main(){
   int k,m;
   while(cin>>k,k){
        cin>>m;
        vector<string> taken(k);
        R(i,0,k,1){
            cin>>taken[i];
        }
        bool fulfilled=true;
        while(m--){
            int c,r;
            cin>>c>>r;
            vector<string> avail(c);
            R(i,0,c,1)
                cin>>avail[i];
            if(fulfilled){
                chk(taken,avail,fulfilled,r);
            }
        }
        if(fulfilled)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
   }
}
