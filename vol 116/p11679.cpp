#include<bits/stdc++.h>
using namespace std;
int main(){
    int banks,debentures;
    while(scanf("%d%d",&banks,&debentures),(banks && debentures)){
        int reserves[banks+5];
        for(int i=0;i<banks;i++)
            cin>>reserves[i];
        int debtor,creditor,credit_value,possible=1;
        for(int i=0;i<debentures;i++){
            cin>>debtor>>creditor>>credit_value;
            reserves[debtor-1]-=credit_value;
            reserves[creditor-1]+=credit_value;
        }
        for(int i=0;i<banks;i++){
            if(reserves[i]<0){
                possible=0;
                break;
            }
        }
        if(possible)
            cout<<"S\n";
        else
            cout<<"N\n";
    }
}
