#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    cin.ignore();
    while(tc--){
        string dm;
        int total=0;
        map<string,int>spcs;
        while(getline(cin,dm),dm.size()!=0){
            spcs[dm]++;
            total++;
        }
        for(auto it=spcs.begin();it!=spcs.end();it++){
            printf("%s %.4lf\n",(it->first).c_str(),(double)(it->second)*100/(double)total);
        }
        if(tc)
            cout<<endl;
    }
}
