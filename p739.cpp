#include <cstdio>
#include <cstring>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int vals[100];
char *v[7];
void makeVal(){
	v[0]="AEIOUYWH";
	v[1]="BPFV";
	v[2]="CSKGJQXZ";
	v[3]="DT";
	v[4]="L";
	v[5]="MN";
	v[6]="R";
	R(i,0,7,1){
		R(j,0,strlen(v[i]),1){
			vals[(int)v[i][j]]=i;
		}
	}
}
int main(){
	char word[25];
	makeVal();
	printf("%9s%-10s%15s%s\n"," ","NAME"," ","SOUNDEX CODE");
	while(scanf("%s",word)==1){
		char fst,prev,nw;
		int d[3]={0},k=0,len;
		fst= word[0];
		prev=fst;
		len=strlen(word);
		R(i,1,len,1){
			nw=word[i];
			if(k>=3)
				continue;
			if(vals[(int)prev]==vals[(int)nw]){
				prev=nw;
				continue;
			}
			if(vals[(int)nw]){
				d[k++]=vals[(int)nw];
				prev=nw;
			}
			else{
				prev=nw;
			}
		}
		printf("%9s%-20s%5s%c%d%d%d\n"," ",word," ",fst,d[0],d[1],d[2]);
	}
	printf("%19s%s\n"," ","END OF OUTPUT");
}