#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string binname;
        getline(cin,binname);
        int m,n,b;
        cin>>m>>n>>b;
        map<string,int> prices;
        while(m--){
            string name;
            int p;
            cin>>name>>p;
            prices[name]=p;
        }
        cin.ignore();
        set<pair<int,string>> recipes;
        while(n--){
            string name,ingredient;
            int piece,k,tot=0;
            getline(cin,name);
            cin>>k;
            while(k--){
                cin>>ingredient>>piece;
                tot+=prices[ingredient]*piece;
            }
            if(tot<=b){
                recipes.insert(make_pair(tot,name));
            }
            cin.ignore();
        }
        for(int i=0;i<binname.size();i++)
            binname[i]=toupper(binname[i]);
        cout<<binname<<endl;
        if(!recipes.size())
            cout<<"Too expensive!"<<endl;
        else{
            for(auto it=recipes.begin();it!=recipes.end();it++){
                cout<< it->second <<endl;
            }
        }
        cout<<endl;
    }
}
