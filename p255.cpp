#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct Board{
    int x,y;
}King,Queen,NQueen;
int K,Q,NQ,xMoves[]={1,-1,0,0},yMoves[]={0,0,1,-1};
bool isAllowed(){
    Board tmp;
    R(i,0,4,1){
        tmp=King;
        tmp.x+=xMoves[i];
        tmp.y+=yMoves[i];
        if(tmp.x==NQueen.x && tmp.y==NQueen.y){
            return false;
        }
    }
    return true;
}
bool isIllegalMove(){
    bool valid=(NQueen.x==Queen.x || NQueen.y==Queen.y);
    bool invalid=(NQueen.x==Queen.x && NQueen.y==Queen.y);
    if(valid & (!invalid)){
        if((NQueen.x!=Queen.x) &&(King.y==Queen.y) ){
            if(Queen.x<King.x && NQueen.x>=King.x){
                return true;
            }
            else if(Queen.x>King.x && NQueen.x<=King.x){
                return true;
            }
            else
                return false;
        }
        else if((NQueen.y!=Queen.y)&&(King.x==Queen.x)){
            if(Queen.y<King.y && NQueen.y>=King.y){
                return true;
            }
            else if(Queen.y>King.y && NQueen.y<=King.y){
                return true;
            }
            else
                return false;
        }
        else
            return false;
        
    }
    else
        return true;
}
bool kingMoves(){
    Board tmp;
    R(i,0,4,1){
        tmp=King;
        tmp.x+=xMoves[i];
        tmp.y+=yMoves[i];
        if(tmp.x<0||tmp.x>7||tmp.y>7||tmp.y<0){
            continue;
        }
        else if(!(tmp.x==NQueen.x || tmp.y==NQueen.y)){
            return true;
        }
    }
    return false;
}
int main(){
    while(cin>>K>>Q>>NQ){
        if(K==Q){
            puts("Illegal state");
        }
        else{
            King.x=K%8,King.y=K/8,Queen.x=Q%8,Queen.y=Q/8,NQueen.x=NQ%8,NQueen.y=NQ/8;
            if(isIllegalMove()){
                puts("Illegal move");
            }
            else{
                if(!isAllowed()){
                    puts("Move not allowed");
                }
                else{
                    if(kingMoves()){
                        puts("Continue");
                    }
                    else{
                        puts("Stop");
                    }
                }
            }
        }
    }
}
