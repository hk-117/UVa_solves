#include<bits/stdc++.h>
using namespace std;

int main(){
    int c=1,t;
    while(scanf("%d",&t),t){
        int ar[t],treat=0,baki=0;
        for(int i=0;i<t;i++){
            scanf("%d",&ar[i]);
            if(ar[i]==0)
                treat+=1;
            else
                baki+=1;
        }
        cout<<"Case "<<c<<": "<<baki-treat<<"\n";
        c++;
    }
    return 0;
}
