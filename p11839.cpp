#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    while(cin>>N,N){
        int tmp;
        while(N--){
            stack<int> B;
            for(int i=0;i<5;i++){
                cin>>tmp;
                if(tmp<=127)
                    B.push(i);
            }
            if(B.size()==1){
                cout<< (char)('A'+ B.top()) << "\n";
            }
            else
                cout<< "*\n";
        }
    }
}
