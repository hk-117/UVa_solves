#include<bits/stdc++.h>
using namespace std;
vector<int> indeg(150),Vars;
vector<int> G[150];
void allTopsort(vector<char> & lst,bitset<150> visited){
  bool endList=true;;
  for(int i=0;i<Vars.size();i++){
    if(indeg[Vars[i]]==0 && !visited[Vars[i]]){
      for(int j=0;j<G[Vars[i]].size();j++)
        indeg[G[Vars[i]][j]]--;
      lst.push_back(Vars[i]);
      visited[Vars[i]]=true;
      allTopsort(lst,visited);
      visited[Vars[i]]=false;
      lst.erase(lst.end()-1);
      for(int j=0;j<G[Vars[i]].size();j++)
        indeg[G[Vars[i]][j]]++;
      endList=false;
    }
  }
  if(endList){
    for(int i=0;i<lst.size();i++){
      printf("%c",lst[i]);
    }
    printf("\n");
  }
}
int main(){
  bool fs=false;
  string line1,line2;
  while(getline(cin,line1)){
    if(!fs) fs=true;
    else printf("\n");
    getline(cin,line2);
    stringstream ss(line1),ps(line2);
    char c,d;
    Vars.clear();
    indeg.assign(150,0);
    for(int i=0;i<150;i++) G[i].clear();
    while(ss>>c){
      Vars.push_back(c);
    }
    sort(Vars.begin(),Vars.end());
    while(ps>>c>>d){
      G[c].push_back(d);
      indeg[d]++;
    }
    bitset<150> visited;
    visited.reset();
    vector<char> lst;
    allTopsort(lst,visited);
  }
}
