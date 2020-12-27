#include<bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    scanf("%d",&N);
    string M,tmp;
    vector<pair<string,int>> Table;
    getchar();
    while(getline(cin,tmp),tmp.size()){
      M+=tmp;
    }
    Table.push_back(make_pair(M,0));
    tmp=M;
    for(int i=1;i<N;i++){
      tmp+=tmp[0];
      tmp.erase(tmp.begin());
      if(i==1)
        M=tmp;
      Table.push_back(make_pair(tmp,i));
    }
    sort(Table.begin(),Table.end());
    int pos= find(Table.begin(),Table.end(),make_pair(M,1))-Table.begin();
    printf("%d\n",pos);
    for(int i=0;i<N;i++){
      if((i+1)%50==0 && i<N-1)
        printf("%c\n",Table[i].first[N-1]);
      else
        printf("%c",Table[i].first[N-1]);
    }
    putchar('\n');
    if(T)
      putchar('\n');
  }
}
