#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int L;
    while(cin>>L,L){
        string decision,last="+x";
        R(i,1,L,1){
            cin>>decision;
            if(decision=="No")
                continue;
            if(last=="+x"){
                last= decision;
            }
            else if(last=="+y"){
                if(decision[1]!='z'){
                    if(decision=="+y")
                        last="-x";
                    else
                        last="+x";
                }
            }
            else if(last=="+z"){
                if(decision[1]!='y'){
                    if(decision=="+z")
                        last="-x";
                    else
                        last="+x";
                }
            }
            else if(last=="-x"){
                if(decision[0]=='+'){
                    decision[0]='-';
                    last=decision;
                }
                else{
                    decision[0]='+';
                    last=decision;
                }
            }
            else if(last=="-y"){
                if(decision[1]!='z'){
                    if(decision=="+y")
                        last="+x";
                    else
                        last="-x";
                }
            }
            else if(last=="-z"){
                if(decision[1]!='y'){
                    if(decision=="+z")
                        last="+x";
                    else
                        last="-x";
                }
            }
        }
        cout<<last<<endl;
    }
}
