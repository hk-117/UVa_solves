#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,c=1;
    scanf("%d",&t);
    while(t--){
        int stud;
        scanf("%d",&stud);
        int spds[stud];
        for(int i=0;i<stud;i++){
            scanf("%d",&spds[i]);
        }
        sort(spds,spds+stud);
        printf("Case %d: %d\n",c,spds[stud-1]);
        c++;
    }
}
