#include<bits/stdc++.h>
using namespace std;
string Haab[19]={
    "pop","no","zip","zotz","tzec",
    "xul","yoxkin","mol","chen","yax", 
    "zac","ceh","mac","kankin","muan",
    "pax","koyab","cumhu","uayet"
};
string Tzolkin[20]={
    "imix","ik","akbal","kan","chicchan",
    "cimi","manik","lamat","muluk", "ok", 
    "chuen","eb","ben","ix","mem", "cib", 
    "caban", "eznab", "canac", "ahau"
};
map<string,int> IDx;
void makeMap(){
    int i;
    for(i=0;i<19;i++){
        IDx[Haab[i]]=i;
    }
}
int main(){
    int n,day,year,month;
    string mon;
    char dot;
    scanf("%d",&n);
    printf("%d\n",n);
    makeMap();
    for(int i=1;i<=n;i++){
        int total_days;
        cin>>day>>dot>>mon>>year;
        month=IDx[mon];
        total_days=year*365+(month*20)+day;
        int ansYear= total_days/260;
        total_days -= (260*ansYear);
        mon= Tzolkin[total_days%20];
        int ansDay=total_days%13 +1;
        cout<< ansDay<<" "<<mon<<" "<<ansYear<<"\n";
    }
}
