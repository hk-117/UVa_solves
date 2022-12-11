#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    map<int,int> numbers;
    vector<int> indices;
    int inp;
    while(cin>>inp){
        numbers[inp]++;
        if(find(indices.begin(),indices.end(),inp)==indices.end()){
            indices.push_back(inp);
        }
    }
    for(auto it=indices.begin();it!=indices.end();it++){
        cout<< *it <<" "<< numbers[*it]<<endl;
    }
}
