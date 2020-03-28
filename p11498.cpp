#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    while(scanf("%d",&T),T){
        int x,y;
        scanf("%d%d",&x,&y);
        while(T--){
            int posx,posy;
            scanf("%d%d",&posx,&posy);
            if(abs(posx==x) || abs(posy)==abs(y)){
                printf("divisa\n");
            }
            else if((posx-x)<0 && (posy-y)>0){
                printf("NO\n");
            }
            else if((posx-x)<0 && (posy-y)<0){
                printf("SO\n");
            }
            else if((posx-x)>0 && (posy-y)>0){
                printf("NE\n");
            }
            else if((posx-x)>0 && (posy-y)<0){
                printf("SE\n");
            }
            
        }
    }

}
