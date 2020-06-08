#include<bits/stdc++.h>
using namespace std;
void factorize(int n,int start,vector<vector<int>>&all,vector<int>&factors){
    for(int i=start;i*i<=n;i++){
        if(n%i==0){
            factors.push_back(i);
            factorize(n/i,i,all,factors);
            factors.pop_back();
        }
    }
    if(!factors.empty()){
        all.push_back(factors);
        all.back().push_back(n);
    }

}
int main(){
    int n;
    while(cin>>n,n){
        vector<vector<int>> all;
        vector<int> factors;
        factorize(n,2,all,factors);
        cout<< all.size()<<endl;
        for(int i=0;i<all.size();i++){
            for(int j=0;j<all[i].size();j++){
                if(j)
                    cout<<" ";
                cout<<all[i][j];
            }
            cout<<endl;
        }
    }
}
