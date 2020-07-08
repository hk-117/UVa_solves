#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define pillar -1
#define sticker 1
#define normal 0
#define ms(a,b) memset(a,b,sizeof(a));
using namespace std;
struct status{
    int x,y,collection=0;
    char orient;
}current;
const int xmoves[]={0,0,1,-1},ymoves[]={1,-1,0,0};
int coordinates[101][101];
string ins;
int xmax,ymax,s;
void moveForward(){
    if(current.orient=='N'){
        current.x+= xmoves[3];
        current.y+= ymoves[3];
    }
    else if(current.orient=='S'){
        current.x+=xmoves[2];
        current.y+=ymoves[2];
    }
    else if(current.orient=='L'){
        current.x+=xmoves[0];
        current.y+=ymoves[0];
    }
    else{
        current.x+=xmoves[1];
        current.y+=ymoves[1];
    }
}
bool isBarrier(){
    if( (current.x<0) || (current.y<0) || (current.x>xmax-1) || (current.y>ymax-1) || (coordinates[current.x][current.y]== pillar))
        return true;
    else
        return false;
}
int main(){
    while(cin>>xmax>>ymax>>s,(xmax||ymax||s)){
        R(i,0,xmax,1){
            string line;
            char cmd;
            cin>>line;
            R(j,0,ymax,1){
                cmd= line[j];
                if(cmd=='*'){
                    coordinates[i][j]=sticker;
                }
                else if(cmd=='#'){
                    coordinates[i][j]=pillar;
                }
                else if(cmd == '.'){
                    coordinates[i][j]=normal;
                }
                else{
                    current.x=i;
                    current.y=j;
                    current.orient=cmd;
                    current.collection=0;
                }
            }
        }
        cin>>ins;
        R(i,0,ins.size(),1){
            if(ins[i]=='D'){
                if(current.orient=='N'){
                    current.orient='L';
                }
                else if(current.orient=='S'){
                    current.orient='O';
                }
                else if(current.orient=='L'){
                    current.orient='S';
                }
                else{
                    current.orient='N';
                }
            }
            else if(ins[i]=='E'){
                if(current.orient=='N'){
                    current.orient='O';
                }
                else if(current.orient=='S'){
                    current.orient='L';
                }
                else if(current.orient=='L'){
                    current.orient='N';
                }
                else{
                    current.orient='S';
                }
            }
            else{
                status tmp=current;
                moveForward();
                if(!isBarrier()){
                    if(coordinates[current.x][current.y]==sticker){
                        current.collection++;
                        coordinates[current.x][current.y]=normal;
                    }
                }
                else{
                    current=tmp;
                }
            }
        }
        ins.clear();
        for(int i=0;i<xmax;i++)
            ms(coordinates[i],0);
        printf("%d\n",current.collection);
    }
}
