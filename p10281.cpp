#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    double pspeed=0.0,prevcalc=0.0,ptime=0.0;
    while(getline(cin,inp)){
        int h,m,s,speed;
        if(inp.size()>9){
            sscanf(inp.c_str(),"%d:%d:%d %d",&h,&m,&s,&speed);
            double total_time= h*3600+m*60.0+s;
            double diff= total_time-ptime;
            prevcalc+= diff/3600 * pspeed;
            pspeed=speed;
            ptime=total_time;
        }
        else{
            sscanf(inp.c_str(),"%d:%d:%d",&h,&m,&s);
            double total_time=h*3600+m*60.0+s;
            double diff= total_time - ptime;
            prevcalc+= diff/3600 * pspeed;
            ptime=total_time;
            printf("%s %.2lf km\n",inp.c_str(),prevcalc);
        }
    }
}
