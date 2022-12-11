#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> res,stres,qres,pqres;
        stack<int> sdata;
        queue<int> qdata;
        priority_queue<int> pqdata;
        map<string,bool> status;
        status["stack"]=false,status["queue"]=false,status["pq"]=false;
        int cnt=0,command,x;
        R(i,0,n,1){
            cin>>command>>x;
            if(command==1){
                sdata.push(x);
                qdata.push(x);
                pqdata.push(x);
            }
            else{
                res.push_back(x);
                if(sdata.size()){
                    stres.push_back(sdata.top());
                    sdata.pop();
                }
                if(qdata.size()){
                    qres.push_back(qdata.front());
                    qdata.pop();
                }
                if(pqdata.size()){
                    pqres.push_back(pqdata.top());
                    pqdata.pop();
                }
            }
        }
        if(res==stres){
            cnt++;
            status["stack"]=true;
        }
        if(res==qres){
            cnt++;
            status["queue"]=true;
        }
        if(res==pqres){
            cnt++;
            status["pq"]=true;
        }
        if(cnt==0)
            cout<<"impossible"<<endl;
        else if(cnt==1){
            if(status["stack"])
                cout<<"stack"<<endl;
            else if(status["queue"])
                cout<<"queue"<<endl;
            else
                cout<<"priority queue"<<endl;
        }
        else{
            cout<<"not sure"<<endl;
        }
    }
}
