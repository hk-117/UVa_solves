#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    while(cin>>N,N){
        string text,f,r;
        vector<string> F,R;
        cin.ignore();
        for(int i=1;i<=N;i++){
            getline(cin,f);
            getline(cin,r);
            F.push_back(f);
            R.push_back(r);
        }
        getline(cin,text);
        for(int i=0;i<F.size();i++){
            while(text.find(F[i])!=string::npos){
                text.replace(text.find(F[i]),F[i].size(),R[i]);
            }
        }
        cout<< text <<"\n";
    }
}
