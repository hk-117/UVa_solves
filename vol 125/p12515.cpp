#include<bits/stdc++.h>
using namespace std;
int M,Q;
int findMatch(int lastPos,string Finde,string clipi){
    int mat=0;
    for(int i=0;i<clipi.size();i++){
        if(clipi[i]==Finde[i+lastPos])
            mat++;
    }
    return mat;
}
int bestMatch(string clip,vector<string> &Dbase){
    int best=0,pos=0;
    for(int i=0;i<M;i++){
        if(Dbase[i].size()<clip.size())
            continue;
        int diff=Dbase[i].size() - clip.size(),tmpbst=0;
        for(int j=0;j<=diff;j++){
            int tmp=findMatch(j,Dbase[i],clip);
            if(tmp>tmpbst)
                tmpbst=tmp;
        }
        if(tmpbst>best){
            best=tmpbst;
            pos=i;
        }
    }
    return pos+1;
}
int main(){
    int i;
    cin>>M>>Q;
    vector<string> Dbase(M);
    for(i=0;i<M;i++){
        cin>>Dbase[i];
    }
    string clip;
    for(i=1;i<=Q;i++){
        cin>>clip;
        cout<< bestMatch(clip,Dbase) <<"\n";
    }
}
