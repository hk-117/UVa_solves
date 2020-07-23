#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define mp make_pair
using namespace std;
void polishStr(string &str){
    string a;
    R(i,0,str.size(),1){
        if(str[i] != ' ')
            a+= str[i];
    }
    str=a;
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    cin.ignore();
    while(t--){
        map<pair<string,string>,bool> orders;
        vector<string> P;
        set<pair<string,string>> Pairs;
        string inp;
        while(getline(cin,inp),inp.size()){
            P.push_back(inp);
        }
        R(i,0,P.size()-1,1){
            string a=P[i],b;
            polishStr(a);
            sort(a.begin(),a.end());
            R(j,i+1,P.size(),1){
                b=P[j];
                polishStr(b);
                sort(b.begin(),b.end());
                if(a==b && !(orders[mp(P[i],P[j])]||orders[mp(P[j],P[i])])){
                    if(P[i]<P[j])
                        Pairs.insert(mp(P[i],P[j]));
                    else
                        Pairs.insert(mp(P[j],P[i]));
                    orders[mp(P[i],P[j])]=true;
                    orders[mp(P[j],P[i])]=true;
                }
            }
        }
        for(auto it=Pairs.begin();it!=Pairs.end();it++){
            cout<< it->first <<" = "<<it->second <<endl;
        }
        if(t)
            cout<<endl;
    }
}
