#include <stdio.h>
#include <string.h>
char G[30][30];
int N,M,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int isValid(int i,int j){
    if(i<0||i>=M||j<0||j>=N)
        return 0;
    return 1;
}
int getBlobSize(int i,int j){
    int k,c=1;
    if(!isValid(i,j) || G[i][j]=='0')
        return 0;
    G[i][j]='0';
    for(k=0;k<8;k++)
       c+=getBlobSize(i+dx[k],j+dy[k]);
    return c;
}
int main(){
    int t,nl=0;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        int i=0,j,size,ans=0;
        char line[30];
        if(nl)
            puts("");
        else
            nl=1;
        while(fgets(line,sizeof(line),stdin)){
            size=strcspn(line,"\n");
            if(size==0){
                break;
            }
            else{
                N=size;
                line[N]='\0';
                strcpy(G[i++],line);
            }
        }
        M=i;
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                int cnt=getBlobSize(i,j);
                if(cnt>ans){
                    ans=cnt;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
