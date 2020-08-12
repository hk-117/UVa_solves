#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct Signal{
    double dist;
    int G,Y,R;
};
bool isValid(int speed,vector<Signal> &Sigs){
    R(i,0,Sigs.size(),1){
        double tm= (Sigs[i].dist * 3600.0)/(double)speed;
        int total=(Sigs[i].G + Sigs[i].Y + Sigs[i].R);
        tm= fmod(tm , total);
        if(tm >(Sigs[i].G+Sigs[i].Y)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,tc=0;
    while(cin>>n,n!=-1){
        tc++;
        vector<Signal> Sigs(n);
        R(i,0,n,1){
            cin>> Sigs[i].dist >> Sigs[i].G >> Sigs[i].Y >> Sigs[i].R;
        }
        vector<int> Acceptables;
        R(i,30,61,1){
            if(isValid(i,Sigs)){
                Acceptables.push_back(i);
            }
        }
        if(!Acceptables.size()){
            cout<<"Case "<<tc<<": No acceptable speeds."<<endl;
        }
        else{
            cout<<"Case "<<tc<<":";
            int cnt=0,lw;
            Acceptables.push_back(65);
            lw=Acceptables[0];
            R(i,0,Acceptables.size()-1,1){
                if(Acceptables[i]+1 != Acceptables[i+1]){
                    if(cnt==0){
                        cout<<" "<<lw;
                        if(i != Acceptables.size()-2){
                            cout<<",";
                        }
                        lw=Acceptables[i+1];
                    }
                    else{
                        cout<< " "<<lw<<"-"<<lw+cnt;
                        if(i != Acceptables.size()-2){
                            cout<<",";
                        }
                        lw=Acceptables[i+1];
                        cnt=0;
                    }
                }
                else{
                    cnt++;
                }
            }
            cout<<endl;
        }
    }
}
