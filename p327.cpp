#include<bits/stdc++.h>
using namespace std;
map<char,int> varVal,valInExp;
void initVars(){
  varVal.clear();
  valInExp.clear();
  for(char c='a';c<='z';c++){
    varVal[c]=c-'a'+1;
    valInExp[c]=c-'a'+1;
  }
}
int main(){
  string line;
  int sz;
  while(getline(cin,line)){
    sz=line.size();
    stack<char> Expr;
    initVars();
    char mdl;
    for(int i=0;i<sz;i++){
      if(line[i]==' ')
        continue;
      else{
        if(Expr.empty())
          Expr.push(line[i]);
        else if(line[i]=='+' || line[i]=='-'){
          if(Expr.top()==line[i]){
            mdl=Expr.top();
            Expr.pop();
            if(Expr.empty() || Expr.top()=='+' || Expr.top()=='-'){
              while(line[++i]==' ');
              if(line[i]>='a' && line[i]<='z'){
                if(mdl=='-'){
                  varVal[line[i]]--;
                  valInExp[line[i]]--;
                }
                else{
                  varVal[line[i]]++;
                  valInExp[line[i]]++;
                }
                Expr.push(line[i]);
              }
            }
            else{
              if(mdl=='-'){
                varVal[Expr.top()]--;
              }
              else{
                varVal[Expr.top()]++;
              }
            }
          }
          else{
            Expr.push(line[i]);
          }
        }
        else{
          Expr.push(line[i]);
        }
      }
    }
    int S=0;
    set<char> Seen;
    stack<char> tmp;
    while(!Expr.empty()){
      tmp.push(Expr.top());
      Expr.pop();
    }
    Expr=tmp;
    char op='+';
    while(!Expr.empty()){
      if(Expr.top()!='+' && Expr.top()!='-'){
        Seen.insert(Expr.top());
        if(op=='+')
          S+=valInExp[Expr.top()];
        else
          S-=valInExp[Expr.top()];
        Expr.pop();
      }
      else{
        op=Expr.top();
        Expr.pop();
      }
    }
    cout<<"Expression: "<< line <<endl;
    cout<<"    value = "<<S<<endl;
    for(auto it=Seen.begin();it!=Seen.end();it++)
      cout<<"    "<< *it <<" = "<<varVal[*it]<<endl;
  }
}
