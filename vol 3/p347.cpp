#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
int chk[10];
int isUnique(char *num){
    int i,len;
    ms(chk,0);
    len=strlen(num);
    for(i=0;i<len;i++){
        if(chk[num[i]-'0']){
            return 0;
        }
        else{
            chk[num[i]-'0']=1;
        }
    }
    return 1;
}
int isRun(char *num){
    int len,i=0,j=0,cnt=0;
    len=strlen(num);
    ms(chk,0);
    while(!chk[num[i]-'0']){
        int pos=num[i]-'0';
        chk[pos]=1;
        cnt++;
        i = (i+pos)%len;
    }
    if(cnt==len && i==0)
        return 1;
    else
        return 0;
}
int main(){
    char number[10];
    int nm,cs=0;
    while(scanf("%d",&nm)==1 && nm){
        int found=0;
        while(!found){
            sprintf(number,"%d",nm);
            if(isUnique(number) && isRun(number)){
                printf("Case %d: %d\n",++cs,nm);
                found=1;
            }
            else{
                nm++;
            }
        }
    }
}
