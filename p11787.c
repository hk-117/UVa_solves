#include<stdio.h>
#include<string.h>
#include<math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define mx 510
int vals[100],count[100],check[100];
char dig[]="BUSPFTM";
void makeVal(){
    int i;
    for(i=0;i<7;i++){
        vals[dig[i]]=(int) pow(10,i);
    }
}
int main(){
    int n;
    makeVal();
    scanf("%d",&n);
    getchar();
    while(n--){
        char line[mx];
        int len,prev,prev2,cur,i,flag=1;
        fgets(line,sizeof(line),stdin);
        len=strcspn(line,"\r\n");
        line[len]='\0';
        prev=line[0];
        cur=line[0];
        prev2=line[0];
        ms(count,0);
        ms(check,0);
        for(i=0;i<len;i++){
            cur=line[i];
            if(prev==cur){
                count[cur]++;
                if(count[cur]>9){
                    flag=0;
                    break;
                }
            }
            else{
                if(check[cur]){
                    flag=0;
                    break;
                }
                else{
                    if(vals[prev2]<vals[prev] && vals[prev]>vals[cur]){
                        flag=0;
                        break;
                    }
                    else if(vals[prev2]>vals[prev] && vals[prev]<vals[cur]){
                        flag=0;
                        break;
                    }
                    else{
                        check[prev]=1;
                        prev2=prev;
                        prev=cur;
                        count[cur]++;
                    }
                }
            }
        }
        if(!flag)
            puts("error");
        else{
            int amnt=0;
            for(i=65;i<=90;i++){
                amnt+= count[i]*vals[i];
            }
            printf("%d\n",amnt);
        }
    }
}
