#include<bits/stdc++.h>
using namespace std;
map<string,string> Op;
int main(){
    string in;
    Op["{"]="}";
    Op["("]=")";
    Op["<"]=">";
    Op["["]="]";
    Op["(*"]="*)";
    while(getline(cin,in)){
        stack<string> S;
        int sz=in.size(),i,realSize=0;
        for(i=0;i<sz;i++){
            string tmp;
            tmp+=in[i];
            if(tmp=="["||tmp=="{"|| tmp=="<")
                S.push(tmp);
            else if(tmp=="("){
                if(i+1<sz && in[i+1]=='*'){
                    tmp+=in[i+1];
                    S.push(tmp);
                    i++;
                    realSize-=1;
                }
                else{
                    S.push(tmp);
                }
            }
            else if(tmp=="]"||tmp=="}"||tmp==">"||tmp==")"){
                if(S.size() && Op[S.top()]==tmp){
                    S.pop();
                }
                else{
                    break;
                }
            }
            else if(tmp=="*"){
                if(i+1<sz && in[i+1]==')'){
                    tmp+=in[i+1];
                    i++;
                    realSize -= 1;
                    if(S.size() && Op[S.top()]==tmp){
                        S.pop();
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                continue;
            }
        }
        if(S.size() && in.size()){
            printf("NO %d\n",i+1+realSize);
        }
        else if(!S.size() && i<sz){
            printf("NO %d\n",i+1+realSize);
        }
        else
            puts("YES");
    }
}
