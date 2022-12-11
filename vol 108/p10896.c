#include<stdio.h>
#include<string.h>
char alph[]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        char enc[75],dec[20];
        char *words[40],*p;
        int wordCount=0,lendec,lenenc,i;
        fgets(enc,sizeof(enc),stdin);
        fgets(dec,sizeof(dec),stdin);
        lenenc=strcspn(enc,"\r\n");
        lendec=strcspn(dec,"\r\n");
        enc[lenenc]='\0';
        dec[lendec]='\0';
        p=strtok(enc," ");
        while(p!=0){
            if(strlen(p)==lendec)
                words[wordCount++]=p;
            p=strtok(NULL," ");
        }
        for(i=0;i<26;i++){
            int j,flag=0;
            char wtmp[lendec];
            strcpy(wtmp,dec);
            for(j=0;j<lendec;j++){
                wtmp[j]= alph[dec[j]-'a' + i];
            }
            for(j=0;j<wordCount;j++){
                if(!strcmp(words[j],wtmp)){
                    flag=1;
                    break;
                }
            }
            if(flag)
                putchar(alph[i]);
        }
        putchar('\n');
    }
}
