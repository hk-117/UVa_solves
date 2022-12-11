#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mx 1050
char keyboard[]="`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";
int poses[mx];
void createPos(){
    int i,len;
    len= strlen(keyboard);
    for(i=0;i<len;i++){
        poses[keyboard[i]]= i;
    }
}
int main(){
    int i,len;
    char text[mx];
    createPos();
    while(fgets(text,sizeof(text),stdin)){
        text[strlen(text)-1]='\0';
        len=strlen(text);
        for(i=0;i<len;i++){
            if(text[i]==' ')
                putchar(' ');
            else
                putchar(keyboard[poses[tolower(text[i])]-2]);
        }
        putchar('\n');
    }
}
