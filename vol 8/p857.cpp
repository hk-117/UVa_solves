#include<bits/stdc++.h>
using namespace std;
struct tone{
    int code,note,m,b,t;
};
int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=-1){
        vector<tone> Vt(n);
        tone tmp;
        for(int i=0;i<n;i++){
            scanf("%d %d %d %d %d",&tmp.code,&tmp.note,&tmp.m,&tmp.b,&tmp.t);
            if(tmp.t % 60 <30){
                tmp.t -= (tmp.t%60);
            }
            else{
                tmp.t -= (tmp.t%60);
                tmp.t += 60;
                if(tmp.t>=480){
                    tmp.b++;
                    tmp.t-=480;
                }
            }
            if(tmp.b>=5){
                tmp.b -= 4;
                tmp.m++;
            }
            Vt[i]=tmp;
        }
        int i=0;
        while(i<Vt.size()){
            bool flg=false;
            for(int j=i+1;j<Vt.size();j++){
                if(Vt[i].note==Vt[j].note && Vt[i].m==Vt[j].m && Vt[i].b==Vt[j].b && Vt[i].t==Vt[j].t){
                    if(Vt[i].code==1 && Vt[j].code==0){
                        Vt.erase(Vt.begin()+j);
                        Vt.erase(Vt.begin()+i);
                        flg=true;
                        break;
                    }
                }
            }
            if(!flg)
                i++;
        }
        cout<<Vt.size()<<"\n";
        for(int i=0;i<Vt.size();i++){
            printf("%d %d %d %d %d\n",Vt[i].code,Vt[i].note,Vt[i].m,Vt[i].b,Vt[i].t);
        }
    }
    printf("-1\n");
}
