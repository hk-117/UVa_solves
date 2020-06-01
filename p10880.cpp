#include<bits/stdc++.h>
using namespace std;

int main(){
    int cs,cas=1;
    cin>>cs;
    while(cs--){
        long long c,r;
        cin>>c>>r;
        cout<<"Case #"<<cas++ <<":";
        if(c==r){
            cout<<" "<<0;
        }
        else{
            set<long long> guests;
            for(int i=1;i*i<=(c-r);i++){
                if((c-r)%i==0){
                    guests.insert((c-r)/i);
                    guests.insert(i);
                }
            }
            for(auto it=guests.begin();it!=guests.end();it++)
                if(*it >r)
                    cout<<" "<<*it;
        }
        cout<<endl;
    }
}
