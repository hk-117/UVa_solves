#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int A,B,C;
        cin>>A>>B>>C;
        bool solved=false;
        for(int x=-22;x<=22 && !solved;x++){
            if(x*x <= C){
                for(int y=-100;y<=100 && !solved;y++){
                    if(y!=x && x*x+y*y<=C){
                        for(int z=-100;z<=100 && !solved;z++){
                            if(z!=x && z!=y && x+y+z==A && x*y*z==B && x*x+y*y+z*z==C){
                                printf("%d %d %d\n",x,y,z);
                                solved=true;
                            }
                        }
                    }
                }
            }
        }
        if(!solved)
            printf("No solution.\n");
    }
}
