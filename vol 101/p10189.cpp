#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define mx 105
using namespace std;
char field[mx][mx],mines[mx][mx];
int n,m;
int xmoves[]={1,1,1,-1,-1,-1,0,0},ymoves[]={0,1,-1,0,1,-1,1,-1};
bool isValidPos(int i,int j){
    if(i>=n||i<0||j>=m||j<0)
        return false;
    else
        return true;
}
char findNeighbour(int i,int j){
    int cnt=0;
    R(k,0,8,1){
        int a=i,b=j;
        a+=ymoves[k];
        b+=xmoves[k];
        if(isValidPos(a,b)){
            if(field[a][b]=='*')
                cnt++;
        }
    }
    return cnt+'0';
}
int main(){
    int fNo=0,nl=0;
    while(cin>>n>>m,n||m){
        if(nl)
            puts("");
        nl++;
        fNo++;
        string inp;
        R(i,0,n,1){
            cin>>inp;
            R(j,0,m,1){
                field[i][j]=inp[j];
            }
        }
        R(i,0,n,1){
            R(j,0,m,1){
                if(field[i][j]=='*'){
                    mines[i][j]='*';
                    continue;
                }
                mines[i][j]=findNeighbour(i,j);
            }
        }
        printf("Field #%d:\n",fNo);
        R(i,0,n,1){
            R(j,0,m,1){
                cout<<mines[i][j];
            }
            puts("");
        }
    }
}
