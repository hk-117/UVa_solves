#include<bits/stdc++.h>
using namespace std;
vector<int> indeg(100),Vars;
vector<int> G[100];
int sol=0;
void allTopsort(vector<char> & lst,bitset<100> visited){
  bool endList=true;
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
    if(!lst.size()) return;
    sol++;
    for(int i=0;i<lst.size();i++){
      printf("%c",lst[i]);
      if(i!=lst.size()-1)
        printf(" ");
    }
    printf("\n");
  }
}
int main(){
  int T;
  string line1,line2;
  cin>>T;
  cin.ignore();
  cin.ignore();
  while(T--){
    getline(cin,line1);
    getline(cin,line2);
    stringstream ss(line1),ps(line2);
    char c,d;
    string word;
    Vars.clear();
    indeg.assign(100,0);
    for(int i=0;i<100;i++) G[i].clear();
    while(ss>>c){
      Vars.push_back(c);
    }
    sort(Vars.begin(),Vars.end());
    while(ps>>word){
      c=word[0];
      d=word[2];
      G[c].push_back(d);
      indeg[d]++;
    }
    bitset<100> visited;
    visited.reset();
    vector<char> lst;
    sol=0;
    allTopsort(lst,visited);
    if(sol==0) printf("NO\n");
    if(T)
      printf("\n");
    cin.ignore();
  }
}
