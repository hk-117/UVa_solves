#include<bits/stdc++.h>
#define PB push_back
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<string> files;
        string inp;
        int longest=0;
        R(i,0,n,1){
            cin>>inp;
            longest= inp.size() > longest ? inp.size() : longest;
            files.PB(inp);
        }
        sort(files.begin(),files.end());
        int cols= (60-longest)/(longest+2);
        cols++;
        int rows=n/cols;
        if(n-(rows * cols) >0)
            rows++;
        vector<string> lists[rows];
        R(i,0,n,1){
            lists[i%rows].PB(files[i]);
        }
        R(i,1,61,1) cout<< "-";
        cout<<endl;
        R(i,0,rows,1){
            for(auto it= lists[i].begin();it!=lists[i].end();it++){
                if(it == lists[i].end() -1){
                    cout<<left<<setw(longest)<< *it <<endl;
                }
                else{
                    cout<<left<<setw(longest+2)<< *it;
                }
            }
        }
    }
}
