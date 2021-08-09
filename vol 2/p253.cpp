#include<bits/stdc++.h>
using namespace std;
string OSrot[4]={"123456","135246","154326","142536"};
string TFrot[4]={"123456","326154","624351","421653"};
string TFirot[4]={"123456","263415","653421","513462"};
string Rotate(string tmp,string displace){
    string Conv="abcdef";
    for(int i=0;i<6;i++){
        int pos=displace[i]-'1';
        Conv[pos]=tmp[i];
    }
    return Conv;
}
int main(){
    string text;
    while(cin>>text){
        string fst(text.begin(),text.begin()+6);
        string second(text.begin()+6,text.end());
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
            cout<<"TRUE\n";
        else
            cout<<"FALSE\n";
    }
}
