#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    string text,inp,word;
    while(getline(cin,inp)){
        if(inp[inp.size()-1]=='-'){
            inp.erase(--inp.end());
            text+= inp;
        }
        else{
            text+=inp+" ";
        }
    }
    set<string> dictionary;
    for(int i=0;i<text.size();i++){
        if((text[i]>='a' && text[i]<='z')||(text[i]>='A' && text[i]<='Z')|| text[i]=='-'){
            word+= tolower(text[i]);
        }
        else{
            if(word.size())
                dictionary.insert(word);
            word="";
        }
    }
    for(auto it=dictionary.begin();it!=dictionary.end();it++)
        cout<< *it <<endl;
}
