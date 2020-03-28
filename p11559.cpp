#include<bits/stdc++.h>
using namespace std;

int main(){
    int participants,budgets,hotels,weeks;
    while(scanf("%d%d%d%d",&participants,&budgets,&hotels,&weeks) != EOF){
        int bed_price,bed_available[weeks];
        
        int total_cost=0,min_cost=budgets+1;

        while(hotels--){
            cin>>bed_price;
            for(int i=0;i<weeks;i++)
                cin>>bed_available[i];
            if((participants*bed_price)<=budgets){
                for(int i=0;i<weeks;i++){
                    if(bed_available[i]>=participants){
                        total_cost=participants*bed_price;
                        if(total_cost<min_cost){
                            min_cost=total_cost;
                        }
                    }
                }
            }
        }
        if(min_cost<budgets)
            cout<<min_cost<<"\n";
        else
            cout<<"stay home\n";
    }
    return 0;
}
