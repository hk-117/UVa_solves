#include<stdio.h>
#include<string.h>
#include<math.h>
#define mx 10005
char line[mx];
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        int len,i,j,sq;
        fgets(line,sizeof(line),stdin);
        len= strcspn(line,"\r\n");
        line[len]='\0';
        sq= (int) sqrt((double)len);
        if(sq*sq != len){
            puts("INVALID");
        }
        else{
            for(i=0;i<sq;i++){
                for(j=i;j<len;j+=sq){
                    putchar(line[j]);
                }
            }
            putchar('\n');
        }
    }
}
