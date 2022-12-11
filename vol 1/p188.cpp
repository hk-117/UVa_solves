#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int toNum(string word){
    int cd=0;
    for(int i=0;i<word.size();i++){
        cd = cd*32+(word[i]-'a'+1);
    }
    return cd;
}
int main(){
    string inp;
    while(getline(cin,inp)){
        vector<int> wInNum;
        stringstream ss(inp);
        string word;
        while(ss>>word){
            wInNum.push_back(toNum(word));
        }
        int C=*min_element(wInNum.begin(),wInNum.end()),n=wInNum.size();
        while(true){
            bool found=true;
            for(int i=0;i<wInNum.size() && found;i++){
                for(int j=i+1;j<wInNum.size() && found;j++){
                    if((C/wInNum[i])%n == (C/wInNum[j])%n){
                        C=min((C/wInNum[i]+1)*wInNum[i],(C/wInNum[j]+1)*wInNum[j]);
                        found=false;
                    }
                }
            }
            if(found)
                break;
        }
        cout<<inp<<endl;
        cout<<C<<endl<<endl;
    }
}
