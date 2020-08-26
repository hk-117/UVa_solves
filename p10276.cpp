#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
vector<vector<int>> P(51);
int n;
bool isSq(int n){
    int s=sqrt(n);
    return (s*s==n);
}
void findBall(int nm){
    bool found=false;
    for(int i=1;i<=n && !found;i++){
        if(P[i].size()==0){
            P[i].push_back(nm);
            found=true;
            findBall(nm+1);
        }
        else{
            if(isSq(P[i][P[i].size()-1]+nm)){
                found=true;
                P[i].push_back(nm);
                findBall(nm+1);
            }
        }
    }
    if(!found)
        printf("%d\n",nm-1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            P[i].clear();
        findBall(1);
    }
}
