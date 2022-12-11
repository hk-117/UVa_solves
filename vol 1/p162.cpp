#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void TGL(bool &pFrom){
    if(pFrom)
        pFrom=false;
    else
        pFrom=true;
}
int main(){
    string inp;
    while(getline(cin,inp),inp!="#"){
        string dm;
        R(i,1,4,1){
            getline(cin,dm);
            inp+=" "+dm;
        }
        stringstream ss(inp);
        int dk=1;
        deque <int> cards[2];
        while(ss>>dm){
            int vl;
            if(dm[1]=='A'){
                vl=4;
            }
            else if(dm[1]=='K'){
                vl=3;
            }
            else if(dm[1]=='Q'){
                vl=2;
            }
            else if(dm[1]=='J'){
                vl=1;
            }
            else{
                vl=0;
            }
            if(dk%2){
                cards[1].push_front(vl);
            }
            else{
                cards[0].push_front(vl);
            }
            dk++;
        }
        bool lastFace,pFrom=1,wasFace=false,faceEnded=false;
        int keepPop=1;
        queue<int> playing;
        while(true){
            int a;
            if(!cards[pFrom].empty()){
                a= cards[pFrom].front();
                cards[pFrom].pop_front();
                playing.push(a);
            }
            else{
                break;
            }
            if(!a){
                keepPop--;
                if(wasFace){
                    if(!keepPop){
                        faceEnded=true;
                        TGL(pFrom);
                        keepPop=1;
                    }
                }
                else{
                    keepPop=1;
                    TGL(pFrom);
                }
            }
            else{
                wasFace=true;
                lastFace=pFrom;
                keepPop=a;
                TGL(pFrom);
            }
            if(wasFace && faceEnded){
                wasFace=false;
                faceEnded=false;
                while(!playing.empty()){
                    cards[lastFace].push_back(playing.front());
                    playing.pop();
                }
            }
        }
        if(cards[0].empty() && !cards[1].empty()){
            printf("%d%3d\n",2,(int)cards[1].size());
        }
        else if(!cards[0].empty() && cards[1].empty()){
            printf("%d%3d\n",1,(int)cards[0].size());
        }
        else{
            printf("%d%3d\n",pFrom,0);
        }
    }
}
