#include<stdio.h>
#include<string.h>
int main(){
    int t,tc=0,GB[150][55];
    char G[55];
    scanf("%d",&t);
    getchar();
    while(t--){
        int height=-100,depth=100,movement=0,i,j,k,len,space,isnl=1;
        scanf("%s",G);
        len=strlen(G);
        memset(GB,0,sizeof GB);
        for(i=0;i<len;i++){
            if(G[i]=='R'){
                GB[movement+51][i]=1;
                if(height<movement+51)
                    height=movement+51;
                if(depth>movement+51)
                    depth=movement+51;
                movement++;
            }
            else if(G[i]=='F'){
                movement--;
                GB[movement+51][i]=2;
                if(depth>movement+51)
                    depth=movement+51;
                if(height<movement+51)
                    height=movement+51;
            }
            else{
                GB[movement+51][i]=3;
                if(height<movement+51)
                    height=movement+51;
                if(depth>movement+51)
                    depth=movement+51;
            }
        }
        for(i=0;i<len;i++)
            if(GB[height][i]!=0)
                isnl=0;
        printf("Case #%d:\n",++tc);
        for(i=isnl?height-1:height;i>=depth;i--){
            printf("| ");
            space=0;
            for(j=0;j<len;j++){
                if(GB[i][j]==0)
                    space++;
                else if(GB[i][j]==1){
                    for(k=1;k<=space;k++)
                        printf(" ");
                    printf("/");
                    space=0;
                }
                else if(GB[i][j]==2){
                    for(k=1;k<=space;k++)
                        printf(" ");
                    printf("\\");
                    space=0;
                }
                else{
                    for(k=1;k<=space;k++)
                        printf(" ");
                    printf("_");
                    space=0;
                }
            }
            printf("\n");
        }
        printf("+");
        for(i=0;i<=len+1;i++)
            printf("-");
        printf("\n\n");
    }
}
