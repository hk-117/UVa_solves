#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define mx 80
char msg[mx],nums[]={'O','I','Z','E','A','S','G','T','B','P'};
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        int len,i;
        while(fgets(msg,sizeof(msg),stdin)){
            len= strcspn(msg,"\r\n");
            if(!len)
                break;
            for(i=0;i<len;i++){
                if(isalpha(msg[i]) && isupper(msg[i])){
                    putchar(msg[i]);
                }
                else if(msg[i]==' '||msg[i]=='.'||msg[i]==','){
                    putchar(msg[i]);
                }
                else{
                    putchar(nums[msg[i]-'0']);
                }
            }
            putchar('\n');
        }
        if(t)
            putchar('\n');
    }
}
