#include<cstdio>
#include<cstring>
using namespace std;
char ln[1005];
int main(){
	int t,tc=0;
	scanf("%d\n",&t);
	while(t--){
		fgets(ln,sizeof(ln),stdin);
		printf("Case %d: ",++tc);
		char c,prevc;
		int frq=0,digit[3]={0},num=0,sz=strlen(ln);
		ln[sz-1]='A';
		ln[sz]='\0';
		for(int i=0;i<sz+1;i++){
			c=ln[i];
			if(c>='A' && c<='Z'){
				if(frq==3){
					num= digit[0]*100 + digit[1]*10 + digit[2];
				}
				else if(frq==2){
					num = digit[0]*10+ digit[1];
				}
				else{
					num= digit[0];
				}
				for(int i=1;i<=num;i++){
					putchar(prevc);
				}
				prevc=c;
				num=0;
				frq=0;
				memset(digit,0,sizeof(digit));
				
			}
			else{
				digit[frq++]=c-'0';
			}
		}
		puts("");
	}
}