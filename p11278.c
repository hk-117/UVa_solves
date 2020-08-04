#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mx 1005
char Qwerty[]=" `1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char Dvorak[]=" `123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg\'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
int poses[mx];
void makePoses(){
    int i,len;
    len= strlen(Qwerty);
    for(i=0;i<len;i++)
        poses[Qwerty[i]]=i;
}
int main(){
    char line[mx];
    makePoses();
    while(fgets(line,sizeof(line),stdin)){
        int i,len;
        line[strcspn(line,"\r\n")]='\0';
        len= strlen(line);
        for(i=0;i<len;i++)
            putchar(Dvorak[poses[line[i]]]);
        putchar('\n');
    }
}
