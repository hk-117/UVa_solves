#include<stdio.h>
#include<string.h>
#include<ctype.h>
char line[150];
int main(){
    int i,j,size,sum=0;
    char c;
    while(fgets(line,sizeof line,stdin)){
        size=strcspn(line,"\n");
        if(size==0){
           printf("\n"); 
        }
        else{
            line[size]='\0';
            for(i=0;i<size;i++){
                c=line[i];
                if(isdigit(c)){
                    sum+=c-'0';
                }
                else{
                    if(c=='!')
                        puts("");
                    else{
                        for(j=1;j<=sum;j++){
                            if(c=='b')
                                printf(" ");
                            else
                                printf("%c",c);
                        }
                    }
                    sum=0;
                }
            }
            puts("");
        }
    }
}
