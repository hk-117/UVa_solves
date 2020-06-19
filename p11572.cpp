#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int mx=INT_MIN,sz;
        vector<int> seqs;
        map<int,int> flakes;
        while(n--){
            int s;
            cin>>s;
            seqs.push_back(s);
            flakes[s]++;
            if(flakes[s]>1){
                sz= flakes.size();
                mx=max(mx,sz);
                auto it=seqs.begin();
                while(*it != s){
                    flakes.erase(*it);
                    seqs.erase(it);
                }
                flakes.erase(*it);
                while(seqs.size() && seqs[0]==s)
                    seqs.erase(seqs.begin());
                seqs.push_back(s);
                flakes[s]++;
            }
        }
        sz=flakes.size();
        mx=max(mx,sz);
        cout<<mx<<endl;
    }
}
