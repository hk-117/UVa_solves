#include<stdio.h>
#include<string.h>
#define wall -1
#define invalid -2
typedef struct{
    int row,col;
} cell;
int left[13][13],right[13][13],up[13][13],down[13][13],F[13][13];
cell Prevs[500];
void initGraph(int m,int n){
    int i;
    memset(left,0,sizeof left);
    memset(right,0,sizeof right);
    memset(up,0,sizeof up);
    memset(down,0,sizeof down);
    memset(F,0,sizeof F);
    for(i=1;i<=m;i++){
        left[i][1]=wall;
        right[i][n]=wall;
    }
    for(i=1;i<=n;i++){
        up[1][i]=wall;
        down[m][i]=wall;
    }
}
void printBrdr(int col){
   int i,j;
   printf("+");
   for(i=1;i<=col;i++){
       printf("---+");
   }
   printf("\n");
}
int main(){
    int h,w,Srow,Scol,Erow,Ecol,tc=0;
    int Dx[]={0,-1,0,1},Dy[]={-1,0,1,0};
    Prevs[0].row=-1;
    Prevs[0].col=-1;
    while(scanf("%d %d %d %d %d %d",&h,&w,&Srow,&Scol,&Erow,&Ecol)==6){ 
        int i,j,tmp,CurRow=Srow,CurCol=Scol,success=0,counter=0,pRow,pCol;
        if(!(h||w||Srow||Scol||Erow||Ecol))
            break;
        ++tc;
        initGraph(h,w);
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                scanf("%d",&tmp);
                if(tmp==1){
                    right[i][j]=wall;
                }
                else if(tmp==2){
                    down[i][j]=wall;
                }
                else if(tmp==3){
                    right[i][j]=wall;
                    down[i][j]=wall;
                }
                else{
                    continue;
                }
            }
        }
        while(!success){
            if(CurRow==Erow && CurCol==Ecol){
                success=1;
                break;
            }
            if(((left[CurRow][CurCol]!=wall)&&(CurCol>1 && right[CurRow][CurCol-1]!=wall))&&(F[CurRow+Dx[0]][CurCol+Dy[0]]==0)){
                F[CurRow][CurCol]= ++counter;
                Prevs[counter].row=CurRow;
                Prevs[counter].col=CurCol;
                CurRow+=Dx[0];
                CurCol+=Dy[0];
            }
            else if(((up[CurRow][CurCol]!= wall)&&(CurRow>1 && down[CurRow-1][CurCol]!=wall))&&(F[CurRow+Dx[1]][CurCol+Dy[1]]==0)){
                F[CurRow][CurCol]= ++counter;
                Prevs[counter].row=CurRow;
                Prevs[counter].col=CurCol;
                CurRow+=Dx[1];
                CurCol+=Dy[1];
            }
            else if((right[CurRow][CurCol]!=wall)&&(F[CurRow+Dx[2]][CurCol+Dy[2]]==0)){
                F[CurRow][CurCol]= ++counter;
                Prevs[counter].row=CurRow;
                Prevs[counter].col=CurCol;
                CurRow+=Dx[2];
                CurCol+=Dy[2];
            }
            else if((down[CurRow][CurCol]!=wall)&&(F[CurRow+Dx[3]][CurCol+Dy[3]]==0)){
                F[CurRow][CurCol]= ++counter;
                Prevs[counter].row=CurRow;
                Prevs[counter].col=CurCol;
                CurRow+=Dx[3];
                CurCol+=Dy[3];
            }
            else{
                F[CurRow][CurCol]=invalid;
                CurRow=Prevs[counter].row;
                CurCol=Prevs[counter].col;
                if(CurRow<0 || CurCol<0)
                    break;
                --counter;
            }
        }
        F[CurRow][CurCol]= ++counter;
        printf("Maze %d\n\n",tc);
        printBrdr(w);
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                if(left[i][j]== wall) printf("|");

                if(F[i][j]== invalid) printf("???");
                else if(F[i][j]==0) printf("   ");
                else printf("%3d",F[i][j]);

                if(right[i][j]==wall) printf("|");
                else printf(" ");
            }
            printf("\n");
            if(i!=h){
                int upI=i;
                printf("+");
                for(j=1;j<=w;j++){
                    if(down[upI][j]==wall){
                        printf("---+");
                    }
                    else{
                        printf("   +");
                    }
                }
                printf("\n");
            }
        }
        printBrdr(w);
        printf("\n\n");
    }
}
