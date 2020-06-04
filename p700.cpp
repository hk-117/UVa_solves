#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int t,tc=0;
    while(cin>>t,t){
        int years[t],a,b,bug[t],actual_year=INT_MIN;
        R(i,0,t,1){
            cin>>years[i]>>a>>b;
            bug[i]= b-a;
            actual_year= actual_year>years[i] ? actual_year:years[i];
        }
        while(actual_year<10000){
            bool fl=0;
            R(i,0,t,1){
                if((actual_year-years[i])%bug[i] != 0){
                    break;
                }
                else{
                    if(i==t-1){
                        fl=1;
                    }
                }
            }
            if(fl)
                break;
            actual_year++;
        }
        printf("Case #%d:\n",++tc);
        if(actual_year==10000){
            printf("Unknown bugs detected.\n\n");
        }
        else{
            printf("The actual year is %d.\n\n",actual_year);
        }
    }
}
