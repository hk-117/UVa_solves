#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int row[8],tc,a,b,lc;
int put(int r,int c){
    int i;
    for(i=0;i<c;i++){
        if(row[i]==r||(abs(row[i]-r)==abs(i-c)))
            return 0;
    }
    return 1;
}
void backtrack(int c){
    int i;
    if(c==8 && row[b]==a){
        int j;
        printf("%2d      %d",++lc,row[0]+1);
        for(j=1;j<8;j++){
            printf(" %d",row[j]+1);
        }
        putchar('\n');
    }
    for(i=0;i<8;i++){
        if(put(i,c)){
            row[c]=i;
            backtrack(c+1);
        }
    }
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        memset(row,0,sizeof(row));
        lc=0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);
        if(tc)
            putchar('\n');
    }
}
