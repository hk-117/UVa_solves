#include<stdio.h>
#include<string.h>
#define mx 115
int Magic[]={27,0,18,1,28,2,19,29,9,30,3,10,31,20,4,11,21,32,12,5,33,22,6,13,34,23,14,35,15,7,24,16,25,8,26,17};
char msg[mx];
int main(){
    int len,i,j;
    while(fgets(msg,sizeof(msg),stdin)){
        int lp;
        char tmp[mx];
        len=strcspn(msg,"\r\n");
        msg[len]='\0';
        lp= len/36;
        for(i=0;i<lp;i++){
            for(j=0;j<36;j++){
                tmp[i*36+Magic[j]]=msg[i*36+j];
            }
        }
        for(i=0;tmp[i]=='#';i++){
            tmp[i]='\0';
        }
        for(i=len-1;tmp[i]!='\0';i--){
                putchar(tmp[i]);
        }
        putchar('\n');
    }
}
