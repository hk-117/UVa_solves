#include<stdio.h>
#include<string.h>
char codes[10][15];
int main(){
    int n=0,sete=0;
    char bcod[15];
    while(fgets(bcod,sizeof(bcod),stdin)){
        int i,j;
        bcod[strcspn(bcod,"\r\n")]='\0';
        if(!strcmp(bcod,"9")){
            int flag=1;
            for(i=0;i<n && flag;i++){
                for(j=0;j<n && flag;j++){
                    char *ps;
                    if(i!=j){
                        ps= strstr(codes[j],codes[i]);
                        if(ps-codes[j]==0){
                            flag=0;
                        }
                    }
                }
            }
            if(flag){
                printf("Set %d is immediately decodable\n",++sete);
            }
            else{
                printf("Set %d is not immediately decodable\n",++sete);
            }
            n=0;
        }
        else{
            strcpy(codes[n++],bcod);
        }
    }
}
