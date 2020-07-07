#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct status{
    int x,y;
    char orient;
    bool lst=0;
}current;
const int xmoves[]={0,0,1,-1},ymoves[]={1,-1,0,0};
int coordinates[51][51];
bool lost[51][51];
char ins[105];
int xmax,ymax;
void moveForward(){
    if(current.orient=='N'){
        current.x+= xmoves[0];
        current.y+= ymoves[0];
    }
    else if(current.orient=='S'){
        current.x+=xmoves[1];
        current.y+=ymoves[1];
    }
    else if(current.orient=='E'){
        current.x+=xmoves[2];
        current.y+=ymoves[2];
    }
    else{
        current.x+=xmoves[3];
        current.y+=ymoves[3];
    }
}
bool isLost(){
    if(current.x<0 || current.y<0 || current.x>xmax || current.y>ymax)
        return true;
    else
        return false;
}
int main(){
    scanf("%d %d",&xmax,&ymax);
    while(scanf("%d %d %c",&current.x,&current.y,&current.orient)==3){
        scanf("%s",ins);
        R(i,0,strlen(ins),1){
            if(ins[i]=='R'){
                if(current.orient=='N'){
                    current.orient='E';
                }
                else if(current.orient=='S'){
                    current.orient='W';
                }
                else if(current.orient=='E'){
                    current.orient='S';
                }
                else{
                    current.orient='N';
                }
            }
            else if(ins[i]=='L'){
                if(current.orient=='N'){
                    current.orient='W';
                }
                else if(current.orient=='S'){
                    current.orient='E';
                }
                else if(current.orient=='E'){
                    current.orient='N';
                }
                else{
                    current.orient='S';
                }
            }
            else{
                if(!lost[current.x][current.y]){
                    status tmp=current;
                    moveForward();
                    if(isLost()){
                        lost[tmp.x][tmp.y]=true;
                        tmp.lst=1;
                        current=tmp;
                        break;
                    }
                }
                else{
                    status tmp=current;
                    moveForward();
                    if(isLost()){
                        current=tmp;
                    }
                }
            }
        }
        if(current.lst){
            printf("%d %d %c LOST\n",current.x,current.y,current.orient);
            current.lst=0;
        }
        else
            printf("%d %d %c\n",current.x,current.y,current.orient);
    }
}
