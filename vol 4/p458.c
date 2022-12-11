#include<stdio.h>
#include<string.h>
char line[10005];
int main(){
	int sz,i;
	while(fgets(line,sizeof(line),stdin)){
		sz= strlen(line);
		line[sz-1]='\0';
		sz--;
		for(i=0;i<sz;i++){
			line[i]= line[i]-7;
		}
		printf("%s\n",line);
	}
}