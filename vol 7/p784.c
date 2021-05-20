#include<stdio.h>
#include<string.h>
int dr[]={0,0,-1,1};
int dc[]={-1,1,0,0};
int lLen[35],R;
char Grid[35][85];
void paint(int r,int c,char c1,char c2){
    int d;
    if(r<0||r>=R||c<0||c>=lLen[r])
        return;
    if(Grid[r][c]!=c1)
        return;
    Grid[r][c]=c2;
    for(d=0;d<4;d++)
        paint(r+dr[d],c+dc[d],c1,c2);
}
int main(){
    int r,c,n,i;
    scanf("%d",&n);
    getchar();
    while(n--){
        char *s;
        R=0;
        while(fgets(Grid[R],sizeof Grid[R],stdin)){
            lLen[R]=strcspn(Grid[R],"\n");
            Grid[R][lLen[R]]='\0';
            if(Grid[R][0]=='_')
                break;
            s=strchr(Grid[R],'*');
            if(s){
                r=R;
                c=s-Grid[R];
                Grid[r][c]=' ';
            }
            R++;
        }
        paint(r,c,' ','#');
        for(i=0;i<R+1;i++)
            printf("%s\n",Grid[i]);
    }
}
