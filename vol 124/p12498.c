#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
char D[55][55];
int R,C;
int findZero(int r,int c){
    int tmp=100,pos=-1,i,j;
    if(D[r][c]=='0')
        return c;
    for(i=0;i<C;i++){
        if(D[r][i]=='0'){
            if(tmp> abs(i-c)){
                tmp=abs(i-c);
                pos=i;
            }
        }
    }
    return pos;
}
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int i,j,possible=1,min=INT_MAX;
        scanf("%d %d",&R,&C);
        getchar();
        for(i=0;i<R;i++){
            scanf("%s",D[i]);
        }
        for(i=0;i<C && possible;i++){
            int val=0;
            for(j=0;j<R && possible;j++){
                int pos=findZero(j,i);
                if(pos==-1){
                    possible=0;
                }
                else{
                    val+= abs(pos-i);
                }
            }
            if(val<min){
                min=val;
            }
        }
        if(possible){
            printf("Case %d: %d\n",++tc,min);
        }
        else{
            printf("Case %d: %d\n",++tc,-1);
        }
    }
}
