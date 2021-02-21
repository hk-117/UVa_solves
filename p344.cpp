#include<bits/stdc++.h>
using namespace std;
string AtoR(int A){
    map<int, string> cvt;
    cvt[1000] = "M"; cvt[900] = "CM"; cvt[500] = "D"; cvt[400] = "CD";
    cvt[100]  = "C"; cvt[90]  = "XC"; cvt[50]  = "L"; cvt[40]  = "XL";
    cvt[10]   = "X"; cvt[9]   = "IX"; cvt[5]   = "V"; cvt[4]   = "IV";
    cvt[1]= "I";
    map<int,string>::reverse_iterator i;
    string st;
    for (i=cvt.rbegin();i != cvt.rend(); i++){
        while (A >= i->first) {
            st+= i->second;
            A -= i->first; 
        }
    }
    return st;
}
int main(){
    int N;
    while(scanf("%d",&N)==1 && N){
        map<char,int> C;
        for(int j=1;j<=N;j++){
            string R= AtoR(j);
            for(int i=0;i<R.size();i++){
                C[R[i]]++;
            }
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",N,C['I'],C['V'],C['X'],C['L'],C['C']);
    }
}
