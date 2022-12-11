#include<stdio.h>
#include<string.h>
char B[105][105];
int maxSize=-1,Bsize[105];
int main(){
    char line[105];
    int N=0,i,j,size;
    while(fgets(line,sizeof line,stdin)){
        size=strcspn(line,"\n");
        line[size]='\0';
        Bsize[N]=size;
        if(size > maxSize)
            maxSize=size;
        strcpy(B[N],line);
        N++;
    }
    for(i=0;i<maxSize;i++){
        for(j=N-1;j>=0;j--){
            if(Bsize[j]>i)
                printf("%c",B[j][i]);
            else
                printf(" ");
        }
        puts("");
    }
}
