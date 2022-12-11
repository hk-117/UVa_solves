#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int fn;
    while(cin>>fn, fn){
        map<vector<string> ,int> popu;
        int mp=0;
        vector<string> comb(5);
        while(fn--){
            R(i,0,5,1){
                cin>>comb[i];
            }
            sort(comb.begin(),comb.end());
            popu[comb]++;
            mp = mp > popu[comb] ? mp:popu[comb];
        }
        int stud=0;
        for(auto it=popu.begin();it!=popu.end();it++){
            if(it->second == mp)
                stud+=mp;
        }
        cout<<stud<<endl;
    }
}
