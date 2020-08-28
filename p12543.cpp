#include<bits/stdc++.h>
using namespace std;
int main(){
    string l,longest,wrd;
    int lsz=-1,ws=0;
    while(getline(cin,l)){
        l+=" ";
        for(int i=0;i<l.size();i++){
            if((l[i]>='a'&&l[i]<='z')||(l[i]>='A'&&l[i]<='Z')||l[i]=='-'){
                ws++;
                wrd+=l[i];
            }
            else{
                if(ws>lsz){
                    longest=wrd;
                    wrd="";
                    lsz=ws;
                    ws=0;
                }
                wrd="";
                ws=0;
            }
        }
    }
    for(int i=0;i<lsz;i++){
        putchar(tolower(longest[i]));
    }
    putchar('\n');
}
