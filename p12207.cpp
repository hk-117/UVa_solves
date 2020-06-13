#include<bits/stdc++.h>
using namespace std;

int main(){
    long long p;
    int c,tc=0;
    while(cin>>p>>c, p&&c){
        tc++;
        deque<long long> ln;
        for(long long i=1;i<=p && i<=1000;i++)
            ln.push_back(i);
        cout<<"Case "<<tc<<":"<<endl;
        while(c--){
            string command;
            cin>>command;
            if(command=="N"){
                cout<<ln.front()<<endl;
                ln.push_back(ln.front());
                ln.pop_front();
            }
            else{
                long long em;
                cin>>em;
                ln.erase(find(ln.begin(),ln.end(),em));
                ln.push_front(em);
            }
        }
    }
}
