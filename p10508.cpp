/* 10508_Word Morphing */
#include <bits/stdc++.h>
using namespace std;

bool isOneDiff(string current,string test){
    int cnt=0;
    for(int i=0;i<current.size();i++)
        if(current[i]!=test[i])
            cnt++;
    if(cnt>1)
        return false;
    return true;
}

int main(){
    int lineSize,wordSize;
    string I,F;
    vector<string> M;
    while(cin>>lineSize>>wordSize){
        cin>>I>>F;
        lineSize-=2;
        string tmp;
        for(int i=1;i<=lineSize;i++){
            cin>>tmp;
            M.push_back(tmp);
        }
        vector<string> Ordered;
        string current=I;
        Ordered.push_back(current);
        while(M.size()){
            for(int i=0;i<M.size();i++){
                if(isOneDiff(current,M[i])){
                    Ordered.push_back(M[i]);
                    current=M[i];
                    M.erase(M.begin()+i);
                }
            }
        }
        Ordered.push_back(F);
        for(int i=0;i<Ordered.size();i++){
            cout<<Ordered[i]<<"\n";
        }
    }
}

