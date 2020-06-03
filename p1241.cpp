#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        bitset<1024> players;
        players.set();
        int wo=0;
        R(i,0,m,1){
            int dm;
            cin>>dm;
            players.reset(dm-1);
        }
        R(i,0,n,1){
            int pos=0;
            int siz= pow(2,n-i);
            R(j,2,siz+1,2){
                if(!(players[j-2] && players[j-1]) && (players[j-2]||players[j-1])){
                    wo++;
                    players[pos++]= players[j-2]||players[j-1];
                }
                else{
                    players[pos++]= players[j-2]||players[j-1];
                }
            }
        }
        cout<<wo<<endl;
    }
}
