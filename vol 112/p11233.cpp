#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool vowl(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    else
        return 0;
}
int main(){
    int l,n;
    cin>>l>>n;
    map<string,string> irre;
    string w1,w2;
    R(i,0,l,1){
        cin>>w1>>w2;
        irre[w1]=w2;
    }
    R(i,0,n,1){
        cin>>w1;
        if(irre.find(w1) != irre.end()){
            cout<< irre[w1] <<endl;
        }
        else{
            char a,b;
            a=w1[w1.size()-1];
            b=w1[w1.size()-2];
            if(a=='y' && (!vowl(b))){
                w1.replace(w1.size()-1,1,"ies");
                cout<<w1<<endl;
            }
            else if(a=='o'||a=='s'||(b=='c'&&a=='h')||(b=='s'&&a=='h')||a=='x'){
                cout<<w1<<"es"<<endl;
            }
            else{
                cout<<w1<<"s"<<endl;
            }
        }
    }
}
