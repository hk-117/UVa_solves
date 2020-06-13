#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        set<int,greater<int>> priorities;
        queue<pair<int,int>> jobs;
        map<int,int> prfrequency;
        int n,m;
        cin>>n>>m;
        R(i,0,n,1){
            int dm;
            cin>>dm;
            priorities.insert(dm);
            prfrequency[dm]+=1;
            jobs.push(make_pair(i,dm));
        }
        int tm=1;
        while(priorities.size()){
            int done=false;
            int prt= *priorities.begin();
            priorities.erase(priorities.begin());
            int pos=1;
            while(prfrequency[prt]) {
                if(jobs.front().second != prt){
                    jobs.push(jobs.front());
                    jobs.pop();
                    pos++;
                }
                else{
                    if(jobs.front().first==m){
                        done=true;
                        break;
                    }
                    else{
                        prfrequency[prt]--;
                        jobs.pop();
                        tm++;
                        pos++;
                    }
                }
            }
            if(done)
                break;
        }
        cout<<tm<<endl;
    }
}
