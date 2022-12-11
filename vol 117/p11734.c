#include<stdio.h>
#include<string.h>
int main(){
    int n,tc=0;
    scanf("%d",&n);
    getchar();
    while(n--){
        char name1[25],name2[25];
        int len1,len2;
        fgets(name1,sizeof(name1),stdin);
        fgets(name2,sizeof(name2),stdin);
        len1=strcspn(name1,"\r\n");
        len2=strcspn(name2,"\r\n");
        name1[len1]='\0';
        name2[len2]='\0';
        printf("Case %d: ",++tc);
        if(len1==len2){
            if(!strcmp(name1,name2)){
                puts("Yes");
            }
            else{
                puts("Wrong Answer");
            }
        }
        else{
            int i,j=0;
            char nmtmp[25];
            for(i=0;i<len1;i++){
                if(name1[i] != ' '){
                    nmtmp[j++]=name1[i];
                }
            }
            nmtmp[j]='\0';
            if(!strcmp(nmtmp,name2)){
                puts("Output Format Error");
            }
            else{
                puts("Wrong Answer");
            }
        }
    }
}
