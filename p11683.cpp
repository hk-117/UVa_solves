#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int a,c;
    while(cin>>a>>c,a&&c){
        vector<int> finlen(c);
        R(i,0,c,1){
            cin>>finlen[i];
        }
        int ton=a-finlen[0];
        R(i,0,c-1,1){
            if((a-finlen[i+1])>(a-finlen[i]))
                ton+= finlen[i]-finlen[i+1];
        }
        cout<<ton<<endl;
    }
}
