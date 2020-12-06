#include<bits/stdc++.h>
using namespace std;
int main(){
  string line;
  int T,tc=0;
  scanf("%d",&T);
  getchar();
  while(T--){
    getline(cin,line);
    string tmp;
    double res=0.0;
    for(int i=0;i<line.size();i++){
      if(line[i]>='0' && line[i]<='9'){
        tmp+=line[i];
      }
      else{
        tmp+=" ";
      }
    }
    stringstream ss(tmp);
    int a,b=0,cnt=1,tp;
    while(ss>>tp){
      if(cnt==1){
        a=tp;
        cnt++;
      }
      else{
        b=tp;
      }
    }
    printf("Case %d: %g\n",++tc,a*0.5+b*0.05);
  }
}
