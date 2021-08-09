#include<bits/stdc++.h>
using namespace std;
string OSrot[4]={"123456","126345","125634","124563"};
string TFrot[4]={"123456","463251","213654","643152"};
string TFirot[4]={"123456","531426","215436","352416"};
string Rotate(string tmp,string displace){
    string Conv="abcdef";
    for(int i=0;i<6;i++){
        int pos=displace[i]-'1';
        Conv[pos]=tmp[i];
    }
    return Conv;
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string fst,second;
        cin>>fst>>second;
        bool found=false;
        for(int i=0;i<4 && !found;i++){
            string snd;
            fst=Rotate(fst,OSrot[i]);
            snd=fst;
            for(int j=0;j<4 && !found;j++){
                string trd;
                snd=Rotate(snd,TFrot[j]);
                trd=snd;
                for(int k=0;k<4 && !found;k++){
                    trd=Rotate(trd,TFirot[k]);
                    if(trd==second){
                        found=true;
                    }
                }
            }
        }
        if(found)
            cout<<"Equal\n";
        else
            cout<<"Not Equal\n";
    }
}
