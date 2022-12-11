#include<bits/stdc++.h>
using namespace std;
int wordDiff(string a,string b){
  int diff,lena=a.size(),lenb=b.size();
  diff=abs(lena-lenb);
  if(lena>lenb){
    for(int i=0;i<lenb;i++){
      if(a[i]!=b[i])
        diff++;
    }
  }
  else if(lenb>lena){
    for(int i=0;i<lena;i++){
      if(a[i]!=b[i])
        diff++;
    }
  }
  else{
    for(int i=0;i<lena;i++){
      if(a[i]!=b[i])
        diff++;
    }
  }
  return diff;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    vector<string> Dict;
    map<string,int> Mpr;
    int pos=1;
    string wrd;
    while(cin>>wrd,wrd!="*"){
      Dict.push_back(wrd);
      Mpr[wrd]=pos;
      pos++;
    }
    vector<int> G[pos+1];
    for(int i=0;i<Dict.size();i++){
      for(int j=i+1;j<Dict.size();j++){
        if(wordDiff(Dict[i],Dict[j])==1){
          G[i+1].push_back(j+1);
          G[j+1].push_back(i+1);
        }
      }
    }
    string st,en,line;
    cin.ignore();
    while(getline(cin,line),line.size()){
      stringstream ss(line);
      ss>>st>>en;
      int init=Mpr[st],fin=Mpr[en];
      vector<int> dist(pos+1,-1);
      queue<int> q;
      dist[init]=0;
      q.push(init);
      while(!q.empty()){
        int u=q.front();q.pop();
        for(int j=0;j<G[u].size();j++){
          int v= G[u][j];
          if(dist[v]==-1){
            dist[v]=dist[u]+1;
            q.push(v);
          }
        }
      }
      cout<<st<<" "<<en<<" "<<dist[Mpr[en]]<<"\n";
    }
    if(t) cout<<"\n";
  }
}
