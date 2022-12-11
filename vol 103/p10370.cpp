#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    cin>>c;
    while(c--){
        int n,inp;
        cin>>n;
        int al[n],sum=0;
        double avg;
        for(int i=1;i<=n;i++){
            cin>>inp;
            sum+=inp;
            al[i-1]=inp;
        }
        avg = (double)sum/(double)n;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(al[i]>avg)
                cnt++;
        }
        printf("%.3lf%%\n",(double)cnt/(double)n *100);
    }
}
