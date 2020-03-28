#include<bits/stdc++.h>

using namespace std;
bool cmp(pair<int,string>a,pair<int,string>b){
    return a.first>b.first;
}
int main(){
    int tc,c=1;
    cin>>tc;
    while(tc--){
        vector<pair<int , string>>lst;
        for(int i=0;i<10;i++){
            string tmp;
            int rank;
            cin>>tmp>>rank;
            pair<int ,string>o=make_pair(rank,tmp);
            lst.push_back(o);
        }
        sort(lst.begin(),lst.end(),cmp);
        int high=lst[0].first;
        cout<<"Case #"<<c<<":\n";
        for(int i=0;i<10;i++){
            if(lst[i].first==high){
                cout<<lst[i].second<<"\n";
            }
        }
        c++;
        lst.clear();
    }
}
