#include<bits/stdc++.h>
using namespace std;
int main(){
  int T,tc=0;
  int N;
  cin>>T;
  string line;
  while(T--){
    cin>>N;
    cin.ignore();
    printf("Case %d:\n",++tc);
    while(N--){
      getline(cin,line);
      int spcnt=0;
      for(int i=0;i<line.size();i++){
        if(line[i]==' '){
          spcnt++;
          if(spcnt<=1) putchar(' ');
        }
        else{
          putchar(line[i]);
          spcnt=0;
        }
      }
      putchar('\n');
    }
    if(T) putchar('\n');
  }
}
