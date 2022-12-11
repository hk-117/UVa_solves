#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        string in;
        stack<char> S;
        getline(cin,in);
        for(int i=0;i<in.size();i++){
            if(in[i]=='('||in[i]=='[')
                S.push(in[i]);
            else{
                if(in[i]==')' && S.size() && S.top()=='(')
                    S.pop();
                else if(in[i]==']' && S.size() && S.top()=='[')
                    S.pop();
                else{
                    S.push(in[i]);
                    break;
                }
            }
        }
        if(S.size() && in.size())
            puts("No");
        else
            puts("Yes");
    }
}
