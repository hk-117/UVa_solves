#include<bits/stdc++.h>
using namespace std;

int main(){
    int devices,operations,fuse_capasity,sequence=1;
    while(scanf("%d%d%d",&devices,&operations,&fuse_capasity),(devices && operations && fuse_capasity)){
        int consumptions[devices],total_operations[operations],status[devices];
        
        for(int i=0;i<devices;i++){
            status[i]=0;
            cin>>consumptions[i];
        }
        for(int i=0;i<operations;i++)
            cin>>total_operations[i];
        int blown=0,st=0,max=-1;
        for(st=0;st<operations;st++){
            if(status[total_operations[st]-1]==0)
                status[total_operations[st]-1]=1;
            else
                status[total_operations[st]-1]=0;
            int sum=0;
            for(int i=0;i<devices;i++){
                if(status[i])
                    sum+=consumptions[i];
                else
                    continue;
            }
            if(sum>fuse_capasity){
                blown=1;
                break;
            }
            else if(max<sum)
                max=sum;
        }
        if(blown){
            cout<<"Sequence "<<sequence<<"\n";
            cout<<"Fuse was blown.\n\n";
        }
        else{
            cout<<"Sequence "<<sequence<<"\n";
            cout<<"Fuse was not blown.\nMaximal power consumption was "<<max<<" amperes.\n\n";
        }
        sequence++;
    }
}
