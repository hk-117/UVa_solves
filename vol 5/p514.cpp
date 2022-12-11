#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        string line;
        cin.ignore();
        while(getline(cin,line),line!="0"){
            stringstream ss(line);
            vector<int> organization;
            stack<int> station;
            int dm;
            while(ss>>dm){
                organization.push_back(dm);
            }
            int at_station=1,need_to_leave=0;
            while(at_station<=n){
                station.push(at_station);
                while(!station.empty() && (station.top()==organization[need_to_leave])){
                    station.pop();
                    need_to_leave++;
                    if(need_to_leave>=n)
                        break;
                }
                at_station++;
            }
            if(station.empty())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
}
