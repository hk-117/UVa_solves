#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mx 10005
int main(){
    int t,tc=0;
    scanf("%d\n",&t);
    while(t--){
        int len;
        char line[mx];
        printf("Case #%d:\n",++tc);
        while(fgets(line,sizeof(line),stdin)){
            char *p;
            int j=1;
            line[strcspn(line,"\r\n")]='\0';
            len= strlen(line);
            if(!len)
                break;
            p= strtok(line," ");
            while(p!=0){
                char *wrd = p;
                int wLen= strlen(wrd);
                if(wLen>=j){
                    printf("%c",wrd[j-1]);
                    j++;
                }
                p = strtok(NULL," ");
            }
            putchar('\n');
        }
        if(t)
            putchar('\n');
    }
}
