#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,u,d,f;
    while(scanf("%d%d%d%d",&h,&u,&d,&f),h>0){
        
        float init=0,climb=u,total=0,fin=0;
        int day=1;
        while(true){
            init=fin;
            total=init+climb;
            if(climb>0)
                climb=climb-(u*f/100.0);
            if(total>h)
                break;
            fin=total-d;
            if(fin<0){
                break;
            }
            day++;
        }
        if(fin<0 || total<0)
            cout<<"failure on day "<<day<<"\n";
        else
            cout<<"success on day "<<day<<"\n";
    }

}
