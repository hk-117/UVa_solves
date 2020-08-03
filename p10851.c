#include<stdio.h>
#include<string.h>
#define mx 100
#define R(i,a,b,c) for(i=a;i<b;i+=c)
int codedH[8][mx];
int main(){
    int n;
    char line[100];
    scanf("%d",&n);
    getchar();
    while(n--){
        int i,j,len,C;
        R(i,0,10,1){
            scanf("%s",line);
            if(i==0||i==9){
                continue;
            }
            len=strlen(line);
            R(j,0,len,1){
                if(j==0||j==len-1)
                    continue;
                else{
                    if(line[j]=='/')
                        codedH[i-1][j-1]=0;
                    else
                        codedH[i-1][j-1]=1;
                }
            }
        }
        R(i,0,len-2,1){
            C=0;
            R(j,0,8,1){
                C+= codedH[j][i]* (1<<j);
            }
            putchar((char) C);
        }
        putchar('\n');
        getchar();
    }
}
