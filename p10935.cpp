#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        queue<int> remaining;
        vector<int> discarded;
        R(i,1,n+1,1){
            remaining.push(i);
        }
        while(remaining.size()!=1){
            discarded.push_back(remaining.front());
            remaining.pop();
            int nxt= remaining.front();
            remaining.pop();
            remaining.push(nxt);
        }
        cout<<"Discarded cards:";
        R(i,0,discarded.size(),1){
            cout<<" ";
            if(!i){
                cout<<discarded[i];
            }
            else if(i == discarded.size()-1){
                cout<<discarded[i];
            }
            else{
                cout<<discarded[i];
            }
            if(discarded.size()>1 && i!=discarded.size()-1)
                cout<<",";
        }
        cout<<endl;
        cout<<"Remaining card: ";
        cout<<remaining.front()<<endl;
    }
}
