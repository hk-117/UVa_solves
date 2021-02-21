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
    string num;
    map<string,int> Tbl;
    for(int i=1;i<=3999;i++){
        Tbl[AtoR(i)]=i;
    }
    while(getline(cin,num)){
        if(Tbl.find(num) != Tbl.end()){
            printf("%d\n",Tbl[num]);
        }
        else
            puts("This is not a valid number");
    }
}
