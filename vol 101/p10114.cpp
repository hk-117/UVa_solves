#include<bits/stdc++.h>
using namespace std;

int main(){
    int month,total_depreciation_record;
    double down_payment,total_loan;
    double records[101];
    while(scanf("%d %lf %lf %d",&month,&down_payment,&total_loan,&total_depreciation_record),(month>0)){
        for(int i=1;i<=total_depreciation_record;i++){
            int mn;
            double rate;
            scanf("%d %lf",&mn,&rate);
            for(int j=mn;j<101;j++)
                records[j]=rate;
        }
        double owes=total_loan,car_worth=total_loan+down_payment,monthly=total_loan/month;
        car_worth=car_worth*(1-records[0]);
        int to_the_month=0;
        while(owes>car_worth){
            to_the_month++;
            owes=owes-monthly;
            car_worth=car_worth*(1-records[to_the_month]);
            
        }
        if(to_the_month==1){
            printf("%d month\n",to_the_month);
        }
        else
            printf("%d months\n",to_the_month);

    }
}
