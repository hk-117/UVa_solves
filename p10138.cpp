#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct event{
    int dy,h,min,pnt;
    bool status;
};
bool fnc(event e1,event e2){
    return ((e1.dy)*24*60+e1.h*60+e1.min)<((e2.dy)*24*60+e2.h*60+e2.min);
}
int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        int fare[24];
        R(i,0,24,1){
            int price;
            cin>>price;
            fare[i]=price;
        }
        map<string,vector<event>> cars;
        cin.ignore();
        string inp;
        while(getline(cin,inp),inp.size()){
            stringstream ss(inp);
            string plate_name,status,tim;
            int point;
            ss>>plate_name;
            ss>>tim;
            ss>>status;
            ss>>point;
            int mn,d,ho,minu;
            sscanf(tim.c_str(),"%d:%d:%d:%d",&mn,&d,&ho,&minu);
            event dm;
            dm.dy=d,dm.h=ho,dm.min=minu,dm.pnt=point;
            dm.status = (status=="exit");
            cars[plate_name].push_back(dm);
        }
        for(auto it=cars.begin();it!=cars.end();it++){
            sort((it->second).begin(),(it->second).end(),fnc);
            double cost=0;
            R(i,0,(it->second).size()-1,1){
                if((it->second)[i].status==0){
                    if((it->second)[i+1].status==1){
                        int dist=abs(it->second[i].pnt - it->second[i+1].pnt);
                        double c= fare[it->second[i].h]/100.0 * (double)dist;
                        cost+=c+1;
                    }
                }
            }
            if(cost!=0)
                cout<< it->first <<" $"<<setprecision(2)<<fixed<<cost+2<<endl;
        }
        if(tc)
            cout<<endl;
    }
}
