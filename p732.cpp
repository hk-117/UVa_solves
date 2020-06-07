//collected

#include<bits/stdc++.h>
using namespace std;
string w_from,w_to;
void solve(string input,string gn_sq,string stk,string op_sq,int tot_op){
    if(tot_op==w_from.length()*2){
        if(gn_sq==w_to)
            cout<<op_sq<<endl;
        return;
    }
    if(input.length()>0)
        solve(input.substr(1,input.length()-1),gn_sq,stk+input[0],op_sq+(tot_op==0?"i":" i"),tot_op+1);
    if(stk.length()>0 && stk[stk.length()-1]==w_to[gn_sq.length()])
        solve(input,gn_sq+stk[stk.length()-1],stk.substr(0,stk.length()-1),op_sq+" o",tot_op+1);


}
int main(){
    while(cin>>w_from>>w_to){
        cout<<"["<<endl;
        string cm1=w_from,cm2=w_to;
        sort(cm1.begin(),cm1.end());
        sort(cm2.begin(),cm2.end());
        if(cm1==cm2){
            solve(w_from,"","","",0);
        }
        cout<<"]"<<endl;
    }
}
