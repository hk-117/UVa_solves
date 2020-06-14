#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void process_inp(string &inp,map<string,int> &freqs, int &total){
    R(i,0,inp.size(),1){
        inp[i]=tolower(inp[i]);
    }
    char *c =new char[inp.size()+1];
    strcpy(c,inp.c_str());
    char *p =strtok(c," ,.:;!?\"()");
    while(p!=NULL){
        string a(p);
        freqs[a]++;
        total++;
        p=strtok(NULL," ,.:;!?\"()");
    }
}
int main(){
    string inp;
    while(getline(cin,inp),inp!="****END_OF_INPUT****"){
        int total=0;
        map<string,int> freqs;
        process_inp(inp,freqs,total);
        while(getline(cin,inp),inp!="****END_OF_TEXT****"){
            process_inp(inp,freqs,total);
        }
        double mx = log10((double) total),et=0;
        if(total!=0)
            et = (double) 1 / (double)total;
        double all=0;
        for(auto it=freqs.begin();it!=freqs.end();it++){
            all+=(it->second)*(log10((double)total)-log10((double)it->second));
        }
        et *= all;
        int er= round((et/mx) * 100);
        cout<<total<<" "<< setprecision(1)<<fixed<< et <<" ";
        cout<< er <<endl;
    }
}
