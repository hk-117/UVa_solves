#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool fnc(int a, int b){
    return abs(a)<abs(b);
}
int main(){
    int p;
    cin>>p;
    while(p--){
        int floors;
        cin>>floors;
        int all[floors];
        R(i,0,floors,1){
            cin>>all[i];
        }
        sort(all,all+floors,fnc);
        int prev,possible=0;
        if(floors>0){
            prev=all[0];
            possible++;
        }
        R(i,0,floors,1){
            if(prev<0 && all[i]<0){
                prev=all[i];
                continue;
            }
            else if(prev>0 && all[i]>0){
                prev=all[i];
                continue;
            }
            else{
                possible++;
                prev=all[i];
            }
        }
        printf("%d\n",possible);
    }
}
