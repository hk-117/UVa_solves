#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,cs=1;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int cl_records[N];
        for(int i=0;i<N;i++){
            cin>>cl_records[i];
        }
        int mile=0,juice=0;
        for(int i=0;i<N;i++){
            int full,par;
            full=cl_records[i]/30;
            if((cl_records[i]%30)>0)
                par=1;
            mile+=(full+par)*10;

            full=cl_records[i]/60;
            if((cl_records[i]%60)>0)
                par=1;
            juice+=(full+par)*15;
        }
        if(mile<juice)
            cout<<"Case "<<cs++ <<": Mile "<<mile<<"\n";
        else if(mile>juice)
            cout<<"Case "<<cs++ <<": Juice "<<juice<<"\n";
        else
            cout<<"Case "<<cs++ <<": Mile Juice "<<juice<<"\n";
    }

}
