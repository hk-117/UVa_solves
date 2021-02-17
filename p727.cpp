#include<bits/stdc++.h>
using namespace std;
int priority(char c){
    if(c=='*'||c=='/')
        return 1;
    else
        return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        char in;
        string postFix,inp;
        stack<char> St;
        St.push('(');
        while(getline(cin,inp),inp.size()){
            in=inp[0];
            if(in=='('){
                St.push(in);
            }
            else if(in==')'){
                while(St.top() != '('){
                    postFix+=St.top();
                    St.pop();
                }
                St.pop();
            }
            else if(isdigit(in)){
                postFix+=in;
            }
            else{
                char tmp=St.top();
                while((tmp=='+'||tmp=='-'||tmp=='*'||tmp=='/')&&(tmp!='(')&&(priority(St.top())>=priority(in))){
                    postFix+=St.top();
                    St.pop();
                    tmp=St.top();
                }
                St.push(in);
            }
        }
        while(St.size() && St.top()!='('){
            postFix+=St.top();
            St.pop();
        }
        printf("%s\n",postFix.data());
        if(t)
            printf("\n");
    }
}
