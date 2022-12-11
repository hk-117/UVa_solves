#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int row[8],tc,CB[8][8],mx=0;
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
    if(c==8){
        int j,su=0;
        for(j=0;j<8;j++){
            su+= CB[row[j]][j];
        }
        if(mx<su)
            mx=su;
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
        int i,j;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                scanf("%d",&CB[i][j]);
            }
        }
        backtrack(0);
        printf("%5d\n",mx);
        mx=0;
    }
}
