#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    cout<<"Lumberjacks:\n";
    while(N--){
        int lin[10];
        for(int i=0;i<10;i++){
            cin>>lin[i];
        }
        int flag=0;
        if(lin[0]>lin[1]){
            for(int i=0;i<9;i++){
                if(lin[i+1]>lin[i]){
                   flag=1;
                   break;
                }
            }
        }
        else{
            
            for(int i=0;i<9;i++){
                if(lin[i+1]<lin[i]){
                   flag=1;
                   break;
                }
            }
        }
        if(flag)
            cout<<"Unordered\n";
        else
            cout<<"Ordered\n";
    }

}
