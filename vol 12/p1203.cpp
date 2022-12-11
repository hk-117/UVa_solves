#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    priority_queue<pair<pair<int,int>,int>> Queries;
    string inp;
    while(getline(cin,inp),inp!="#"){
        stringstream ss(inp);
        string a;
        int b,c;
        ss>>a;
        ss>>b;
        ss>>c;
        Queries.push(make_pair(make_pair(-c,-b),-c));
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cout<< -Queries.top().first.second <<endl;
        int a=Queries.top().first.first,b=Queries.top().first.second,c=Queries.top().second;
        Queries.pop();
        a+=c;
        Queries.push(make_pair(make_pair(a,b),c));
    }
}
