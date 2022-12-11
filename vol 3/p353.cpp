#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define npos string::npos
using namespace std;
bool isPalindrome(string pl){
    int n=pl.size();
    R(i,0,n/2+1,1){
        if(pl[i]!=pl[n-1-i])
            return false;
    }
    return true;
}
int main(){
    string inp;
    while(cin>>inp){
        int n=inp.size(),pl=0;
        map<string,bool> unq;
        R(i,0,n,1){
            R(j,i,n+1,1){
                string sub(inp.begin()+i,inp.begin()+j);
                if((sub!="") && (!unq[sub]) && (isPalindrome(sub))){
                    unq[sub]=true;
                    pl++;
                }
            }
            
        }
        printf("The string '%s' contains %d palindromes.\n",inp.c_str(),pl);
    }
}
