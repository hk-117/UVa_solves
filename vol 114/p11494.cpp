#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,a,b;
    while(scanf("%d %d %d %d",&x,&y,&a,&b)==4 && (x||y||a||b)){
        if(abs(x-a)==abs(y-b)){
            if(x-a==0){
                puts("0");
            }
            else{
                puts("1");
            }
        }
        else{
            if(x-a==0 || y-b==0)
                puts("1");
            else
                puts("2");
        }
    }
}
