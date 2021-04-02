#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3],b[3];
    while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1],(a[0]||a[1]||a[2]||b[0]||b[1])){
        bitset<53> d;
        d[a[0]]=1;
        d[a[1]]=1;
        d[a[2]]=1;
        d[b[0]]=1;
        d[b[1]]=1;
        sort(a,a+3);
        if(b[0]>b[1])
            swap(b[0],b[1]);
        int cnt=0,cutb[2]={0,0};
        for(int i=0;i<=2;i++){
            for(int j=0;j<=1;j++){
                if(a[i]>b[j] && !cutb[j]){
                    cutb[j]=i+1;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt<=1){
            if(cnt==0)
                b[2]=1;
            else{
                if(cutb[0]==3){
                    b[2]=a[1];
                }
                else
                    b[2]=a[2];
            }
            int i;
            for(i=b[2];i<=52;i++){
                if(!d[i]){
                    b[2]=i;
                    break;
                }
            }
            if(i>52)
                cout<< -1 <<"\n";
            else
                cout<< b[2] <<"\n";
        }
        else
            cout << -1 <<"\n";
    }
}
