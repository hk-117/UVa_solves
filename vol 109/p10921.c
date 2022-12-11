#include<stdio.h>
#include<string.h>
char codes[9][5]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
int nms[100];
void makeMap(){
    int i,j,len;
    for(i=0;i<8;i++){
        len= strlen(codes[i]);
        for(j=0;j<len;j++){
            nms[codes[i][j]]=i+2;
        }
    }
}
int main(){
    char phn[35];
    makeMap();
    while(fgets(phn,sizeof(phn),stdin)){
        int i,len;
        len= strcspn(phn,"\n");
        for(i=0;i<len;i++){
            if(phn[i]>='A' && phn[i]<='Z'){
                printf("%d",nms[phn[i]]);
            }
            else
                printf("%c",phn[i]);
        }
        putchar('\n');
    }
}
