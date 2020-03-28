#include<bits/stdc++.h>
using namespace std;

int main(){
    int peoples,present=1;
    while(scanf("%d",&peoples) != EOF){
        string names[peoples];
        for(int i=0;i<peoples;i++){
            cin>>names[i];
        }
        map<string,int> records;
        for(int i=0;i<peoples;i++){
            records[names[i]]=0;
        }
        for(int i=0;i<peoples;i++){
            string giver;
            int total_giving,total_giving_to;
            cin>>giver>>total_giving>>total_giving_to;
            if(total_giving_to>0)
                records[giver] -=(total_giving/total_giving_to)*total_giving_to;
            else
                records[giver] =records[giver];
            for(int j=0;j<total_giving_to;j++){
                string tmp_people;
                cin>>tmp_people;
                records[tmp_people] +=total_giving/total_giving_to;
            }

        }
        if(present++ >1)
            cout<<"\n";
        for(int i=0;i<peoples;i++)
            cout<< names[i] <<" "<< records[names[i]]<<"\n";
        

    }
}
