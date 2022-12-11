#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int y;
    while(cin>>y){
        int p;
        cin>>p;
        vector<int> pps(p);
        R(i,0,p,1){
            cin>>pps[i];
        }
        int period=y,stYear,endYear,larg=INT_MIN;
        for(int i=0;i<p;i++){
            auto it = upper_bound(pps.begin()+i,pps.end(),pps[i]+period-1);
            int cnt=0;
            if(*it != period)
                --it;
            cnt = it-(pps.begin()+i)+1;
            if(cnt>larg){
                larg=cnt;
                stYear = pps[i];
                endYear = *it;
            }
        }
        cin.ignore();
        cout<<larg<<" "<<stYear<<" "<<endYear<<endl;
    }
}
