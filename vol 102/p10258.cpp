#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct board{
    int tmno,solved=0,total_time=0,subm=0;
    map<int,int>delays;
    map<int,bool>sol_status;

    void getinp(int pno,int subt,char status){
        subm++;
        if(status=='C' && !sol_status[pno]){
            total_time+=subt + delays[pno];
            solved++;
            sol_status[pno]=true;
        }
        else if(status=='I'){
            delays[pno]+=20;
        }
        else{
            //do nothing
        }
    }
    bool operator<(const board& a){
        if(solved==a.solved){
            if(total_time==a.total_time){
                return tmno<a.tmno;
            }
            else
                return total_time<a.total_time;
        }
        else
            return solved>a.solved;
    }
};
void init(vector<board> &logs_all){
    R(i,0,100,1)
        logs_all[i].tmno = i+1;
}
int main(){
    int cases;
    cin>>cases;
    getchar();
    getchar();
    while(cases--){
        int tmno,pno,subt,maxtm=0;
        char status;
        string buf;
        vector<board> logs_all(100);
        init(logs_all);
        while(getline(cin,buf)){
            if(buf.size()==0)
                break;
            sscanf(buf.c_str(),"%d %d %d %c",&tmno,&pno,&subt,&status);
            logs_all[tmno-1].getinp(pno,subt,status);
            maxtm= maxtm>tmno ? maxtm:tmno;
        }
        sort(logs_all.begin(),logs_all.end());
        R(i,0,maxtm,1){
            if(logs_all[i].subm){
                cout<<logs_all[i].tmno<<" "<<logs_all[i].solved<<" "<<logs_all[i].total_time<<endl;
            }
        }
        if(cases)
            cout<<endl;
    }
}
