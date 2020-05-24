#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int minadis(string wfs){
    int mini=INT_MAX;
    R(i,0,wfs.size()-1,1){
        int dist= abs(wfs[i]-wfs[i+1]);
        mini= mini < dist ? mini:dist;
    }
    return mini;
}
bool cmp(pair<int,string> p1, pair<int,string> p2){
    if(p1.first==p2.first)
        return p1.second < p2.second;
    else
        return p1.first>p2.first;
}
int main(){
    string wfs;
    while(cin>>wfs){
        vector<pair<int,string>> perms;
        int minabs= minadis(wfs);
        perms.push_back(make_pair(minabs,wfs));
        string wfs1=wfs,wfs2=wfs;
        R(i,1,11,1){
            next_permutation(wfs1.begin(),wfs1.end());
            minabs=minadis(wfs1);
            perms.push_back(make_pair(minabs,wfs1));
            prev_permutation(wfs2.begin(),wfs2.end());
            minabs=minadis(wfs2);
            perms.push_back(make_pair(minabs,wfs2));
        }
        sort(perms.begin(),perms.end(),cmp);
        cout<<perms[0].second<<perms[0].first<<endl;
    }
}
