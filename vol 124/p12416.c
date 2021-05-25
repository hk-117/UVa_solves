#include<stdio.h>
#include<math.h>
#include<string.h>
#define eps 1e-9
char line[1000005];
int main(){
    int i,spc,len,tmp,ans;
    double lg;
    while(fgets(line,sizeof line,stdin)){
        len=strcspn(line,"\n");
        line[len]='\0';
        spc=-1;
        tmp=0;
        for(i=0;i<len;i++){
            if(line[i]==' ')
                tmp++;
            else{
                if(tmp>spc)
                    spc=tmp;
                tmp=0;
            }
        }
        lg=log(spc)/log(2);
        ans=lg;
        if(lg-ans > eps)
            ans++;
        printf("%d\n",ans);
    }
}
