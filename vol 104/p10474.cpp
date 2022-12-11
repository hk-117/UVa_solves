#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q,tc=0;
    while(cin>>n>>q,n||q){
        tc++;
        int m[n];
        for(int i=0;i<n;i++){
            cin>>m[i];
        }
        sort(m,m+n);
        int qi;
        printf("CASE# %d:\n",tc);
        for(int i=0;i<q;i++){
            cin>>qi;
            int* pos = lower_bound(m,m+n,qi);
            if(pos==m+n)
                printf("%d not found\n",qi);
            else if( *pos == qi)
                printf("%d found at %ld\n",qi, pos-m+1);
            else{
                printf("%d not found\n",qi);
            }
        }
    }
}
