#include<bits/stdc++.h>
using namespace std;
int simulate(deque<int> F,int k,int Start){
    int it;
    for(it=1;it<Start;it++){
        F.push_back(F.front());
        F.pop_front();
    }
    while(F.size()>1){
        for(int i=1;i<k;i++){
            F.push_back(F.front());
            F.pop_front();
        }
        F.pop_front();
        int pos=(k-1)%(F.size());
        F.push_back(*(F.begin()+pos));
        F.erase(F.begin()+pos);
    }
    return F.front();
}
int main(){
    int N,k;
    while(scanf("%d %d",&N,&k)==2 && (N||k)){
        int i;
        deque<int> F;
        for(i=1;i<=N;i++) F.push_back(i);
        i=1;
        while(i<=N){
            int res=simulate(F,k,i);
            if(res==1)
                break;
            i++;
        }
        printf("%d\n",i);
    }
}
