#include<bits/stdc++.h>
using namespace std;
int calCost(string f,string s){
    set<char> fc,sc;
    for(int i=0;i<f.size();i++){
        fc.insert(f[i]);
    }
    for(int i=0;i<s.size();i++){
        sc.insert(s[i]);
    }
    int cost=0;
    for(auto it=fc.begin();it!=fc.end();it++){
        if(sc.find(*it)==sc.end())
            cost++;
    }
    for(auto it=sc.begin();it!=sc.end();it++){
        if(fc.find(*it)==fc.end())
            cost++;
    }
    return cost;
}
int main(){
    int DS;
    cin>>DS;
    while(DS--){
        string S;
        int K,cost=0;
        cin>>K;
        int cutPos[K];
        for(int i=0;i<K;i++)
            cin>> cutPos[i];
        cin>>S;
        bool cuts[S.size()+1]={};
        for(int i=0;i<K;i++){
            string f,s;
            int j=cutPos[i]-1,k=cutPos[i]+1;
            cuts[cutPos[i]]=true;
            while(j>=1 && cuts[j]==false){
                j--;
            }
            while(k<=S.size() && cuts[k]==false){
                k++;
            }
            f.assign(S,j,cutPos[i]-j);
            s.assign(S,cutPos[i],k-cutPos[i]);
            cost+=calCost(f,s);
        }
        cout<<cost<<"\n";
    }
}
