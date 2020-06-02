#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct person{
    string name;
    int day,month,year;
    
    bool operator<(const person& a){
        if(year==a.year){
            if(month==a.month){
                return day>a.day;
            }
            else
                return month>a.month; 
        }
        else
            return year>a.year;
    }
};

int main(){
    int n;
    cin>>n;
    person all[n];
    R(i,0,n,1){
        cin>> all[i].name >> all[i].day >>all[i].month >>all[i].year;
    }
    sort(all,all+n);
    cout<<all[0].name<<"\n"<<all[n-1].name<<endl;
    
}
