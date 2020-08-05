#include<stdio.h>
#include<string.h>
#define DWN 27
#define UP 31
char Sftd[2][40];
int to_num(char *c){
    int n=0,i;
    for(i=0;i<5;i++){
        n += (c[i]-'0')* (1<<(4-i));
    }
    return n;
}
int main(){
    char line[100];
    fgets(Sftd[0],sizeof(Sftd[0]),stdin);
    fgets(Sftd[1],sizeof(Sftd[1]),stdin);
    Sftd[0][strcspn(Sftd[0],"\r\n")]='\0';
    Sftd[1][strcspn(Sftd[1],"\r\n")]='\0';
    while(fgets(line,sizeof(line),stdin)){
        int len,i,sStatus=0;
        len=strcspn(line,"\r\n");
        line[len]='\0';
        for(i=0;i<len;i+=5){
            char w[6];
            int pos;
            strncpy(w,line+i,5);
            pos=to_num(w);
            if(pos == DWN){
                sStatus=0;
            }
            else if(pos== UP){
                sStatus=1;
            }
            else{
                putchar(Sftd[sStatus][pos]);
            }
        }
        putchar('\n');
    }
}
