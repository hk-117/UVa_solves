#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    return (y==0 ? x: gcd(y,x%y));
}
int calcFact(int len,map<char,int> CharCount, char c){
    CharCount[c]--;
    long long fact=1;
    vector<int> L,H;
    for(int i=2;i<=len-1;i++)
        L.push_back(i);
    for(auto it=CharCount.begin();it!=CharCount.end();it++){
        if(it->second > 1){
            for(int i=2;i<=it->second;i++)
                H.push_back(i);
        }
    }
    for(int i=0;i<L.size();i++){
        fact*=L[i];
        for(int j=0;j<H.size();j++){
            int gc= gcd(fact,H[j]);
            fact/=gc;
            H[j]/=gc;
        }
    }
    int mlt=1;
    for(int i=0;i<H.size();i++)
        mlt*= H[i];
    return (fact/mlt);
}

int findSol(string s){
    int len=s.size();
    if(len<=1)
        return 0;
    set<char> DistChar;
    map<char,int> CharCount;
    for(int i=0;i<len;i++){
        DistChar.insert(s[i]);
        CharCount[s[i]]++;
    }
    int sm=0;
    for(auto it=DistChar.begin();it!=DistChar.end();it++){
        if(*it >= s[0])
            break;
        sm+= calcFact(len,CharCount,*it);
    }
    s.erase(s.begin());
    return sm+findSol(s);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string line;
    while(cin>>line,line!="#"){
        printf("%10d\n",findSol(line)+1);
    }
}
