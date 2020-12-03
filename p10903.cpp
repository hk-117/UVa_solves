#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K,p1,p2;
  string m1,m2;
  bool nl=false;
  while(cin>>N,N){
    cin>>K;
    if(nl)
      putchar('\n');
    else
      nl=true;
    vector<int>Wins(N+1,0),Loss(N+1,0);
    for(int i=1;i<=(K*(N)*(N-1))/2;i++){
      cin>>p1>>m1>>p2>>m2;
      if(m1=="rock"){
        if(m2=="rock"){
          //nothing
        }
        else if(m2=="paper"){
          Wins[p2]++;
          Loss[p1]++;
        }
        else{
          Wins[p1]++;
          Loss[p2]++;
        }
      }
      else if(m1=="paper"){
        if(m2=="rock"){
          Wins[p1]++;
          Loss[p2]++;
        }
        else if(m2=="paper"){
          //nothing
        }
        else{
          Wins[p2]++;
          Loss[p1]++;
        }
      }
      else{
        if(m2=="rock"){
          Wins[p2]++;
          Loss[p1]++;
        }
        else if(m2=="paper"){
          Wins[p1]++;
          Loss[p2]++;
        }
        else{
          //nothing
        }
      }
    }
    for(int i=1;i<=N;i++){
      if(Wins[i]+Loss[i] != 0){
        printf("%.3lf\n",(double)(Wins[i])/(double)(Wins[i]+Loss[i]));
      }
      else
        puts("-");
    }
  }
}
