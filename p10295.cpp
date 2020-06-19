#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    map<string,int> hay;
    while(m--){
        string wor;
        int val;
        cin>>wor>>val;
        hay[wor]=val;
    }
    while(n--){
        string inp;
        int salary=0;
        while(cin>> inp, inp !="."){
            salary+= hay[inp];
        }
        cout<<salary<<endl;
    }
}
