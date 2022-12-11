#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        int n;
        cin>>n;
        vector<string> Words(n);
        R(i,0,n,1)
            cin>>Words[i];
        string test;
        while(cin>>test,test!="END"){
            string a=test;
            sort(a.begin(),a.end());
            printf("Anagrams for: %s\n",test.c_str());
            int cnt=0;
            R(i,0,n,1){
                string b= Words[i];
                sort(b.begin(),b.end());
                if(a==b){
                    printf("%3d) %s\n",++cnt,Words[i].c_str());
                }
            }
            if(!cnt){
                printf("No anagrams for: %s\n",test.c_str());
            }
        }
        cin.ignore();
        if(t)
            puts("");
    }
}
