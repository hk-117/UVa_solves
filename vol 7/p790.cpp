#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct Submission{
    int tmno,hours,mnts;
    string pname,status;
};

struct team{
    int solved=0,t_t=0,tn=0;
    map<string,bool>verdict;
    map<string,int> delays;
};
bool cmp(Submission A,Submission B){
    if(A.hours==B.hours){
        if(A.mnts==B.mnts){
            return A.status<B.status;
        }
        else
            return A.mnts<B.mnts;
    }
    else
        return A.hours<B.hours;
}

bool fnc(team A,team B){
    if(A.solved == B.solved){
        if(A.t_t == B.t_t){
            return A.tn<B.tn;
        }
        else
            return A.t_t<B.t_t;
    }
    else
        return A.solved>B.solved;
}

int main(){
    int tc;
    cin>>tc;
    getchar();
    getchar();
    while(tc--){
        int tmno,maxi=0;
        string solvetime,inp,status,pname;
        vector<Submission> Subm;
        Submission dmsubm;
        while(getline(cin,inp),inp.size()!=0){
            stringstream st(inp);
            int t=0;
            string tmp;
            while(st>>tmp){
                t++;
                if(t==1){
                    tmno=atoi(tmp.c_str());
                    maxi= maxi>tmno ? maxi:tmno;
                }
                else if(t==2)
                    pname=tmp;
                else if(t==3)
                    solvetime=tmp;
                else
                    status=tmp;
            }
            stringstream ss(solvetime);
            int h,m,i=0;
            string dm;
            while(getline(ss,dm,':')){
                i++;
                if(i==1)
                    h=atoi(dm.c_str());
                else
                    m=atoi(dm.c_str());
            }
            dmsubm.tmno=tmno;
            dmsubm.pname=pname;
            dmsubm.hours=h;
            dmsubm.mnts=m;
            dmsubm.status=status;
            Subm.push_back(dmsubm);
        }
        sort(Subm.begin(),Subm.end(),cmp);
        vector<team> logs(maxi);
        R(i,0,maxi,1)
            logs[i].tn= i+1;
        R(i,0,Subm.size(),1){
            if(!(logs[Subm[i].tmno-1].verdict[Subm[i].pname]) && Subm[i].status=="Y"){
                logs[Subm[i].tmno-1].solved +=1;
                logs[Subm[i].tmno-1].verdict[Subm[i].pname]=true;
                logs[Subm[i].tmno-1].t_t += Subm[i].hours *60 + Subm[i].mnts +logs[Subm[i].tmno-1].delays[Subm[i].pname];
            }
            else if(!(logs[Subm[i].tmno-1].verdict[Subm[i].pname]) && Subm[i].status=="N"){
                logs[Subm[i].tmno-1].delays[Subm[i].pname] +=20;
            }
        }
        sort(logs.begin(),logs.end(),fnc);
        cout<<"RANK TEAM PRO/SOLVED TIME\n";
        int p_r=1,prev_solved=logs[0].solved,p_t=logs[0].t_t,m_r=1;
        R(i,0,maxi,1){
            if(logs[i].tn){
                if(logs[i].solved==prev_solved && logs[i].t_t==p_t){
                    cout<<setw(4)<<p_r;
                    m_r++;
                }
                else{
                    p_r=m_r;
                    m_r++;
                    p_t=logs[i].t_t;
                    prev_solved=logs[i].solved;
                    cout<<setw(4)<< p_r;
                }
                cout<<setw(5)<<logs[i].tn;
                if(logs[i].solved){
                    cout<<setw(5)<<logs[i].solved;
                    cout<<setw(11)<<logs[i].t_t;
                }
                cout<<endl;
            }
        }
        if(tc)
            cout<<endl;
    }
}
