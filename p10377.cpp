#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define pillar -1
#define normal 0
#define ms(a,b) memset(a,b,sizeof(a));
using namespace std;
struct status{
    int x,y;
    char orient;
}current;

const int xmoves[]={0,0,1,-1},ymoves[]={1,-1,0,0};
int coordinates[61][61];

void moveForward(){
    if(current.orient=='N'){
        current.x+= xmoves[3];
        current.y+= ymoves[3];
    }
    else if(current.orient=='S'){
        current.x+=xmoves[2];
        current.y+=ymoves[2];
    }
    else if(current.orient=='E'){
        current.x+=xmoves[0];
        current.y+=ymoves[0];
    }
    else{
        current.x+=xmoves[1];
        current.y+=ymoves[1];
    }
}

bool isBarrier(){
    if(coordinates[current.x][current.y]== pillar)
        return true;
    return false;
}

int main(){
    int T,R,C;
    cin>>T;
    while(T--){
        string row;
        cin>>R>>C;
        cin.ignore();
        R(i,0,R,1){
            getline(cin,row);
            R(j,0,C,1){
                if(row[j]=='*'){
                    coordinates[i][j]=pillar;
                }
                else{
                    coordinates[i][j]=normal;
                }
            }
        }
        cin>>current.x>>current.y;
        current.x--;
        current.y--;
        current.orient='N';
        string ins;
        cin.ignore();
        while(getline(cin,ins),ins.size()){
            R(i,0,ins.size(),1){
                if(ins[i]==' ') continue;
                if(ins[i]=='Q') break;
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
                    status tmp=current;
                    moveForward();
                    if(isBarrier()){
                        current=tmp;
                    }
                }
            }
        }
        printf("%d %d %c\n",current.x+1,current.y+1,current.orient);
        if(T)
            puts("");
    }
}
