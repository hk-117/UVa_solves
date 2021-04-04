#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    scanf("%d",&c);
    while(c--){
        int T,N,x,y,a,b;
        scanf("%d %d",&T,&N);
        while(T--){
            scanf("%d %d %d %d",&x,&y,&a,&b);
            if(abs(x-a)==abs(y-b)){
                if(x-a==0){
                    puts("0");
                }
                else{
                    puts("1");
                }
            }
            else{
                if(abs(x-a)%2 == abs(y-b)%2)
                    puts("2");
                else
                    puts("no move");
            }
        }
    }
}
