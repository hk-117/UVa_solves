#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct fUnit{
    int s,e,to;
};
int cltm,st,res;
bitset<10002> mrk;
map<int,vector<fUnit>> S;
int findTarget(int cldto){
    if(!S[cldto].size())
        return cldto;
    if(mrk[cldto])
        return 9999;
    bool found=false;
    R(i,0,S[cldto].size(),1){
        if(cltm>= S[cldto][i].s && cltm<=S[cldto][i].e){
            mrk[cldto]=1;
            return findTarget(S[cldto][i].to);
        }
    }
    if(!found)
        return cldto;
}
int main(){
    int n,syst=0;
    scanf("%d",&n);
    puts("CALL FORWARDING OUTPUT");
    while(n--){
        syst++;
        printf("SYSTEM %d\n",syst);
        S.clear();
        fUnit tmp;
        int frm;
        while(scanf("%d",&frm)==1 && frm){
            scanf("%d %d %d",&tmp.s,&tmp.e,&tmp.to);
            tmp.e= tmp.s + tmp.e;
            S[frm].push_back(tmp);
        }
        while(scanf("%d",&cltm) && cltm!=9000){
            scanf("%d",&st);
            mrk.reset();
            int ans=findTarget(st);
            printf("AT %04d CALL TO %04d RINGS %04d\n",cltm,st,ans);

        }
    }
    puts("END OF OUTPUT");
}
