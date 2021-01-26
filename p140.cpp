#include<bits/stdc++.h>
using namespace std;
string G[26];
int findMaxBand(string BandLin){
  int mx=-1;
  for(int i=0;i<BandLin.size();i++){
    for(int j=0;j<G[BandLin[i]-'A'].size();j++){
      int dist= BandLin.find(G[BandLin[i]-'A'][j]);
      dist= abs(dist-i);
      mx= max(dist,mx);
    }
  }
  return mx;
}
int main(){
  string line;
  while(getline(cin,line),line!="#"){
    string BandLin;
    for(int i=0;i<26;i++)
      G[i].clear();
    char lin[line.size()+1];
    strcpy(lin,line.c_str());
    char *p= strtok(lin,";");
    while(p){
      string a(p);
      G[a[0]-'A'].append(a.begin()+2,a.end());
      for(int i=0;i<a.size();i++){
        if(i==1)
          continue;
        if(BandLin.find(a[i])==string::npos)
          BandLin+=a[i];
      }
      p=strtok(NULL,";");
    }
    sort(BandLin.begin(),BandLin.end());
    int mn=INT_MAX;
    string res;
    do{
      int tmp=findMaxBand(BandLin);
      if(tmp<mn){
        mn=tmp;
        res=BandLin;
      }
    }while(next_permutation(BandLin.begin(),BandLin.end()));
    for(int i=0;i<res.size();i++){
      printf("%c ",res[i]);
    }
    printf("-> %d\n",mn);
  }
}
