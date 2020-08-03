#include<stdio.h>
#include<string.h>
int main(){
    int i,len,n,j;
    char line[15];
    while(fgets(line,sizeof(line),stdin)){
        if(line[0]=='_')
            continue;
        line[strlen(line)-1]='\0';
        len= strlen(line);
        n=0;
        j=0;
        for(i=len-2;i>=1;i--){
            if(line[i]==' '){
                j++;
                continue;
            }
            else if(line[i]=='.')
                continue;
            else{
                n+=(1<<j);
                j++;
            }
        }
        putchar((char) n);
    }
}
