#include<stdio.h>
#include<string.h>
#include<ctype.h>
char line[75];
int main(){
    int lenLine,isLastHyp=0,lastWordPos,i,j;
    while(fgets(line,sizeof line,stdin)){
        lenLine=strcspn(line,"\n");
        line[lenLine]='\0';
        if(!strcmp(line,"#"))
            break;
        i=0;
        if(isLastHyp){
            for(i=0;line[i]!=' ';i++){
                if(isalpha(line[i]) || line[i]==' ')
                    printf("%c",line[i]);
            }
            i;
            printf("\n");
        }
        isLastHyp=0;
        lastWordPos=lenLine-1;
        if(line[lenLine-1]=='-'){
            for(j=lenLine-1;j>=0 && line[j]!=' ';j--){
                lastWordPos=j;
            }
            isLastHyp=1;
        }
        if(!isLastHyp){
            for(i;i<lenLine;i++){
                if(isalpha(line[i]) || line[i]==' ')
                    printf("%c",line[i]);
            }
            printf("\n");
        }
        else{
            for(i;i<lastWordPos;i++){
                if(isalpha(line[i]) || line[i]==' ')
                    printf("%c",line[i]);
            }
            printf("\n");
            for(i=lastWordPos;i<lenLine;i++){
                if(isalpha(line[i]) || line[i]==' ')
                    printf("%c",line[i]);
            }
        }
    }
}
