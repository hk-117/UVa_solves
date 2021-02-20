#include<stdio.h>
#include<string.h>
typedef struct{
    char word[60];
    int SN;
} Word;
Word list[110];
int findSwaps(char *W,int len){
    int i,j,sw=0,spd;
    char tmp;
    for(i=0;i<len;i++){
        spd=0;
        for(j=0;j<len-1;j++){
            if(W[j]>W[j+1]){
                spd=1;
                sw++;
                tmp=W[j];
                W[j]=W[j+1];
                W[j+1]=tmp;
            }
        }
        if(!spd)
            break;
    }
    return sw;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,i,j,spd;
        char line[60];
        scanf("%d %d",&n,&m);
        getchar();
        for(i=0;i<m;i++){
            scanf("%s",line);
            strcpy(list[i].word,line);
            list[i].SN=findSwaps(line,n);
        }
        for(i=0;i<m;i++){
            spd=0;
            for(j=0;j<m-1;j++){
                if(list[j].SN>list[j+1].SN){
                    Word tmp=list[j];
                    list[j]=list[j+1];
                    list[j+1]=tmp;
                    spd=1;
                }
            }
            if(!spd)
                break;
        }
        for(i=0;i<m;i++){
            printf("%s\n",list[i].word);
        }
        if(t)
            printf("\n");
    }
}
