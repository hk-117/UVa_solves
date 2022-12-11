#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool fnc(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second){
        if(abs(a.first)%2==1 && abs(b.first)%2==0){
            return (abs(a.first)%2)>(abs(b.first)%2);
        }
        else if(abs(a.first)%2==1 && abs(b.first)%2==1){
            return a.first>b.first;
        }
        else if(abs(a.first)%2==0 && abs(b.first)%2==0){
            return a.first<b.first;
        }
        else{
            //return (abs(a.first)%2)<(abs(b.first)%2);
        }
    }
    return a.second<b.second;
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m), n&&m){
        vector<pair<int,int>> numbers(n);
        R(i,0,n,1){
            scanf("%d",&numbers[i].first);
            numbers[i].second= (numbers[i].first)%m;
        }
        sort(numbers.begin(),numbers.end(),fnc);
        printf("%d %d\n",n,m);
        R(i,0,n,1){
            printf("%d\n",numbers[i].first);
        }
    }
    printf("%d %d\n",n,m);
}
