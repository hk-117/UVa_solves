#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,NW,mx,cnt;
    vector<string> F(11);
    F[1]="qaz";
    F[2]="wsx";
    F[3]="edc";
    F[4]="rfvtgb";
    F[5]=" ";
    F[6]=" ";
    F[7]="yhnujm";
    F[8]="ik,";
    F[9]="ol.";
    F[10]="p;/";
    while(cin>>N>>NW){
        map<char,bool> NotPossible;
        int f;
        set<string> R;
        string w;
        for(int i=1;i<=N;i++){
            cin>>f;
            for(int j=0;j<F[f].size();j++)
                NotPossible[F[f][j]]=true;
        }
        mx=-1;
        cnt=0;
        for(int i=1;i<=NW;i++){
            cin>>w;
            bool possible=true;
            for(int i=0;i<w.size();i++){
                if(NotPossible[w[i]]){
                    possible=false;
                    break;
                }
            }
            if(possible){
                if(R.find(w)!=R.end())
                    continue;
                R.insert(w);
                int len=w.size();
                if(len>mx){
                    mx=len;
                    cnt=1;
                }
                else
                    if(len==mx)
                        cnt++;
            }
        }
        cout<< cnt <<"\n";
        for(auto it=R.begin();it!=R.end();it++){
            if((*it).size()==mx)
                cout<< *it <<"\n";
        }
    }
}
