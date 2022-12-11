#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int PawnY[]={1,-1,1,-1},PawnX[]={1,1,-1,-1};
int KnightY[]={2,2,-2,-2,1,-1,1,-1},KnightX[]={1,-1,1,-1,2,2,-2,-2};
int RookY[]={1,-1,0,0},RookX[]={0,0,1,-1};
int KQY[]={1,1,1,-1,-1,-1,0,0},KQX[]={0,1,-1,0,1,-1,1,-1};
int BishopY[]={1,1,-1,-1},BishopX[]={1,-1,1,-1};
char board[8][8];
struct Piece{
    int x,y;
};
bool invalidMove(int x,int y){
    if(x<=7 && x>=0 && y<=7 && y>=0){
        if((board[x][y])=='x'||(board[x][y])=='.'){
            return false;
        }
        else
            return true;
    }
    else
        return true;
}
void moveQueen(Piece Queen){
    R(i,0,8,1){
        Piece tmp=Queen;
        tmp.x+=KQX[i],tmp.y+=KQY[i];
        while(!invalidMove(tmp.x,tmp.y)){
            board[tmp.x][tmp.y]='x';
            tmp.x+=KQX[i],tmp.y+=KQY[i];
        }
    }
}
void moveKnight(Piece Knight){
    R(i,0,8,1){
        Piece tmp=Knight;
        tmp.x+=KnightX[i],tmp.y+=KnightY[i];
        if(!invalidMove(tmp.x,tmp.y)){
            board[tmp.x][tmp.y]='x';
        }
    }
}
void moveKing(Piece King){
    R(i,0,8,1){
        Piece tmp=King;
        tmp.x+=KQX[i],tmp.y+=KQY[i];
        if(!invalidMove(tmp.x,tmp.y)){
            board[tmp.x][tmp.y]='x';
        }
    }
}
void moveRook(Piece Rook){
    R(i,0,4,1){
        Piece tmp=Rook;
        tmp.x+=RookX[i],tmp.y+=RookY[i];
        while(!invalidMove(tmp.x,tmp.y)){
            board[tmp.x][tmp.y]='x';
            tmp.x+=RookX[i],tmp.y+=RookY[i];
        }
    }
}
void moveBishop(Piece Bishop){
    R(i,0,4,1){
        Piece tmp=Bishop;
        tmp.x+=BishopX[i],tmp.y+=BishopY[i];
        while(!invalidMove(tmp.x,tmp.y)){
            board[tmp.x][tmp.y]='x';
            tmp.x+=BishopX[i],tmp.y+=BishopY[i];
        }
    }
}
void movePawn(Piece Pawn,char WB){
    if(WB=='p'){
        R(i,0,2,1){
            Piece tmp=Pawn;
            tmp.x+=PawnX[i],tmp.y+=PawnY[i];
            if(!invalidMove(tmp.x,tmp.y)){
                board[tmp.x][tmp.y]='x';
            }
        }
    }
    else{
        R(i,2,4,1){
            Piece tmp=Pawn;
            tmp.x+=PawnX[i],tmp.y+=PawnY[i];
            if(!invalidMove(tmp.x,tmp.y)){
                board[tmp.x][tmp.y]='x';
            }
        }
    }
}
int main(){
    string inp;
    while(cin>>inp){
        stringstream ss(inp);
        int row=0;
        string rw;
        while(getline(ss,rw,'/')){
            int k=0;
            R(i,0,rw.size(),1){
                if(isdigit(rw[i])){
                    R(j,0,rw[i]-'0',1){
                        board[row][k++]='.';
                    }
                }
                else{
                    board[row][k++]=rw[i];
                }
            }
            row++;
        }
        R(i,0,8,1){
            R(j,0,8,1){
                if(board[i][j]=='q'||board[i][j]=='Q'){
                    Piece Queen;
                    Queen.x=i,Queen.y=j;
                    moveQueen(Queen);
                }
                else if(board[i][j]=='p'||board[i][j]=='P'){
                    Piece Pawn;
                    Pawn.x=i,Pawn.y=j;
                    movePawn(Pawn,board[i][j]);
                }
                else if(board[i][j]=='k'||board[i][j]=='K'){
                    Piece King;
                    King.x=i,King.y=j;
                    moveKing(King);
                }
                else if(board[i][j]=='r'||board[i][j]=='R'){
                    Piece Rook;
                    Rook.x=i,Rook.y=j;
                    moveRook(Rook);
                }
                else if(board[i][j]=='b'||board[i][j]=='B'){
                    Piece Bishop;
                    Bishop.x=i,Bishop.y=j;
                    moveBishop(Bishop);
                }
                else if(board[i][j]=='n'||board[i][j]=='N'){
                    Piece Knight;
                    Knight.x=i,Knight.y=j;
                    moveKnight(Knight);
                }
                else{
                    continue;
                }
            }
        }
        int notAttacked=0;
        R(i,0,8,1){
            notAttacked+= count(board[i],board[i]+8,'.');
        }
        cout<<notAttacked<<endl;
    }
}
