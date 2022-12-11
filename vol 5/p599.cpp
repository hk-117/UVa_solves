#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string inp;
        map<char,vector<char>>forest;
        int total=0;
        while(cin>>inp,inp[0]!='*'){
            forest[inp[1]].push_back(inp[3]);
            forest[inp[3]].push_back(inp[1]);
            total++;
        }
        cin>>inp;
        vector<char> points;
        char pt;
        char *a= new char[inp.size()+1];
        strcpy(a,inp.c_str());
        char *p=strtok(a,",");
        while(p!=NULL){
            char pt= *p;
            points.push_back(pt);
            p=strtok(NULL,",");
        }
        int acorn=0;
        R(i,0,points.size(),1){
            if(forest[points[i]].size()==0)
                acorn++;
        }
        cout<<"There are "<<points.size()-total-acorn<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;
    }
}
