#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m,num;
        multiset<int> fl,sl;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>num;
            fl.insert(num);
        }
        for(int i=1;i<=m;i++){
            cin>>num;
            sl.insert(num);
        }
        int rm=0;
        while(fl.size() || sl.size()){
            if(fl.size() && sl.size()){
                if(*fl.begin() == *sl.begin()){
                    fl.erase(fl.begin());
                    sl.erase(sl.begin());
                }
                else{
                    if(*fl.begin() < *sl.begin())
                        fl.erase(fl.begin());
                    else
                        sl.erase(sl.begin());
                    rm++;
                }
            }
            else if(fl.size()){
                rm+= fl.size();
                fl.clear();
            }
            else{
                rm+=sl.size();
                sl.clear();
            }
        }
        cout<<rm<<endl;
    }
}
