#include<stdio.h>

int Ticket[5][5],b,Balls[80],Cost[4];
void getTicket();
int getPos(int);
int Corners();
int Midline();
int Diagonals();
int Table();

int main(){
    int t,tc=0,L;
    scanf("%d",&t);
    while(t--){
        int i,j;
        scanf("%d %d",&b,&L);
        for(i=0;i<b;i++){
            scanf("%d",&Balls[i]);
        }
        for(i=0;i<4;i++){
            scanf("%d",&Cost[i]);
        }
        printf("Case %d:\n",++tc);
        while(L--){
            int tvalue=0;
            getTicket();
            if(Corners()){
                tvalue+=Cost[0];
            }
            if(Midline()){
                tvalue+=Cost[1];
            }
            if(Diagonals()){
                tvalue+=Cost[2];
            }
            if(Table()){
                tvalue+=Cost[3];
            }
            printf("%d\n",tvalue);
        }
        if(t)
            printf("\n");
    }
}

void getTicket(){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d",&Ticket[i][j]);
        }
    }
}

int Corners(){
    int x[]={0,0,4,4},y[]={0,4,0,4},i,pos;
    for(i=0;i<4;i++){
        pos=getPos(Ticket[x[i]][y[i]])+1;
        if(pos<1 || pos>35)
            return 0;
    }
    return 1;
}

int Midline(){
    int i,pos;
    for(i=0;i<5;i++){
        pos=getPos(Ticket[2][i])+1;
        if(pos<1 || pos>40)
            return 0;
    }
    return 1;
}

int Diagonals(){
    int i,pos;
    for(i=0;i<5;i++){
        pos=getPos(Ticket[i][i])+1;
        if(pos<1 || pos>45)
            return 0;
        pos=getPos(Ticket[i][4-i])+1;
        if(pos<1 || pos>45)
            return 0;
    }
    return 1;
}

int Table(){
    int i,j;
    for(i=0;i<5;i++){
        int ra=i*15+1,rb=(i+1)*15;
        for(j=0;j<5;j++){
            if(getPos(Ticket[j][i])==-1)
                return 0;
        }
    }
    return 1;
}

int getPos(int val){
    int i;
    for(i=0;i<b;i++){
        if(Balls[i]==val)
            return i;
    }
    return -1;
}
