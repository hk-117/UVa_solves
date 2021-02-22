#include<bits/stdc++.h>
using namespace std;
string AtoR(int A){
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100]  = "C"; cvt[90]  = "XC"; cvt[50]  = "L"; cvt[40]  = "XL";
    cvt[10]   = "X"; cvt[9]   = "IX"; cvt[5]   = "V"; cvt[4]   = "IV";
    cvt[1]= "I";
    map<int,string>::reverse_iterator i;
    string str;
    for (i=cvt.rbegin();i != cvt.rend(); i++){
        while (A >= i->first) {
            str+= i->second;
            A -= i->first; 
        }
    }
    return str;
}
int main(){
    string nm;
    map<char,int> Mat;
    Mat['I']=1;Mat['V']=2;Mat['X']=2;Mat['L']=2;
    Mat['C']=2;Mat['D']=3;Mat['M']=4;
    int n,M;
    while(cin>>n){
        string ans=AtoR(n);
        M=0;
        for(int i=0;i<ans.size();i++){
            M+=Mat[ans[i]];
        }
        cout<<M<<endl;
    }
}
