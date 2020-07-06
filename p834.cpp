#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        vector<int> seq;
        int trm=1;
        int res= a/b;
        seq.push_back(res);
        int md= a%b;
        a=md;
        while(md>0){
            if(trm%2){
                res=b/a;
                seq.push_back(res);
                md= b%a;
                b=md;
                trm++;
            }
            else{
                res=a/b;
                seq.push_back(res);
                md=a%b;
                a=md;
                trm++;
            }
        }
        cout<<"["<<seq[0];
        for(int i=1;i<seq.size();i++){
            if(i==1)
                cout<<";"<<seq[i];
            else
                cout<<","<<seq[i];
        }
        cout<<"]\n";
    }
}
