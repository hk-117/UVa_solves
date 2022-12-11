#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct rvs{
    string mn="AEHIJL3MOSTUVWX2YZ158";
    string rv="A3HILJEMO2TUVWXSY51Z8";
    map<char,int> p;
    void crPos(){
        R(i,1,22,1){
            p[mn[i-1]]=i;
        }
    }
    char findMirror(char c){
        if(!p[c]){
            return '!';
        }
        else
            return rv[p[c]-1];
    }
}Reverses;
bool isMirror(string st){
    int n=st.size();
    R(i,0,n/2+1,1){
        if(!(st[i]==Reverses.findMirror(st[n-1-i])))
            return false;
    }
    return true;
}
bool isPalindrome(string st){
    int n=st.size();
    R(i,0,n/2+1,1){
        if(!(st[i]==st[n-1-i]))
            return false;
    }
    return true;
}
int main(){
    Reverses.crPos();
    string inp;
    while(cin>>inp){
        if(isMirror(inp)){
            if(isPalindrome(inp)){
                cout<<inp<<" -- is a mirrored palindrome.\n\n";
            }
            else{
                cout<<inp<<" -- is a mirrored string.\n\n";
            }
        }
        else{
            if(isPalindrome(inp)){
                cout<<inp<<" -- is a regular palindrome.\n\n";
            }
            else{
                cout<<inp<<" -- is not a palindrome.\n\n";
            }
        }
    }
}
