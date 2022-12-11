#include<cstdio>
#include<cstring>
#define mx 9876543210LL
using namespace std;
bool isUnique(long long num){
    char number[15];
    int chk[11]={0},len,i;
    sprintf(number,"%lld",num);
    len=strlen(number);
    for(i=0;i<len;i++){
        if(chk[number[i]-'0']){
            return false;
        }
        else{
            chk[number[i]-'0']=1;
        }
    }
    return true;
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        long long n,ans,i;
        scanf("%lld",&n);
        for(i=1;i<=mx/n;i++){
            if(isUnique(i) && isUnique(n*i)){
                printf("%lld / %lld = %lld\n",n*i,i,n);
            }
        }
        if(tc)
            putchar('\n');
    }
}
