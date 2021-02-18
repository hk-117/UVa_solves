#include<bits/stdc++.h>
using namespace std;
void simulate(deque<int> F,int k,int m){
    int posA=0,posB=F.size()-1,sft,sz;
    while(F.size()){
        sz=F.size();
        posA=(k-1+posA)%(sz);
        sft=(m-1)%(sz);
        posB= posB-sft;
        if(posB<0){
            posB= posB+sz;
        }
        if(posA==posB){
            if(sz==1){
                printf("%3d",F[posA]);
            }
            else{
                printf("%3d,",F[posA]);
            }
            F.erase(F.begin()+posA);
            posB--;
        }
        else{
            if(F.size()==2){
                printf("%3d%3d",F[posA],F[posB]);
            }
            else{
                printf("%3d%3d,",F[posA],F[posB]);
            }
            if(posA<posB){
                F.erase(F.begin()+posB);
                F.erase(F.begin()+posA);
                posB-=2;
            }
            else{
                F.erase(F.begin()+posA);
                F.erase(F.begin()+posB);
                posB--;
                posA--;
            }
        }
        if(!F.size())
            break;
        posA=(posA%(F.size()+1));
        if(posB<0)
            posB=(posB+F.size())%F.size();
    }
}
int main(){
    int N,k,m;
    while(scanf("%d %d %d",&N,&k,&m)==3 && (N||k||m)){
        int i;
        deque<int> F;
        for(i=1;i<=N;i++) F.push_back(i);
        simulate(F,k,m);
        puts("");
    }
}
