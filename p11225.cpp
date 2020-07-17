#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define npos string::npos
using namespace std;
int main(){
    int tc=0,t;
    cin>>t;
    while(t--){
        tc++;
        int m,oud=0,points=0,OudLers[]={56,51,41,36};
        cin>>m;
        cin.ignore();
        string inp;
        R(i,0,m,1){
            getline(cin,inp);
            if(inp=="fool"||inp=="one of trumps"||inp=="twenty-one of trumps"){
                oud++;
                points+=9;
            }
            else if(inp.find("king")!=npos){
                points+=9;
            }
            else if(inp.find("queen")!=npos){
                points+=7;
            }
            else if(inp.find("knight")!=npos){
                points+=5;
            }
            else if(inp.find("jack")!=npos){
                points+=3;
            }
            else{
                points+=1;
            }
        }
        int requiredPoints=OudLers[oud];
        points/=2;
        printf("Hand #%d\n",tc);
        if(points>=requiredPoints){
            printf("Game won by %d point(s).\n",points-requiredPoints);
        }
        else{
            printf("Game lost by %d point(s).\n",requiredPoints-points);
        }
        if(t)
            puts("");
    }
}
