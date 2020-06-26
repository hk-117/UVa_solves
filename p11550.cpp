#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        bool yes=true;
        map<pair<int,int>,bool> edges;
        R(i,0,n,1){
            R(j,0,m,1){
                cin>>arr[i][j];
            }
        }
        int v1,v2;
        for(int i=0;i<m && yes;i++){
            int rc=0;
            R(j,0,n,1){
                if(arr[j][i]){
                    if(!rc)
                        v1=j;
                    else{
                        v2=j;
                    }
                    rc++;
                }
            }
            if(rc != 2){
                yes=false;
            }
            else{
                if(edges[make_pair(v1,v2)])
                    yes=false;
                edges[make_pair(v1,v2)]=true;
                edges[make_pair(v2,v1)]=true;
            }
        }
        if(yes)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
