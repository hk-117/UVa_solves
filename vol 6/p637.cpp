#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		int rem = n%4;
		printf("Printing order for %d pages:\n",n);
		int ned = n/4 + ((rem==0)?0:1);
		ned *= 4;
		R(i,0,ned/4,1){
			int frnta = 2*i+1; 
			int frntb = ned-2*i;
			int backa =	2*i+2;
			int backb = ned-(2*i+1);
			if(frntb<=n && frnta<=n){
				printf("Sheet %d, front: %d, %d\n",i+1,frntb,frnta);
			}
			else if(frntb>n && frnta<=n){
				printf("Sheet %d, front: Blank, %d\n",i+1,frnta);
			}
			else if(frntb<=n && frnta>n){
				printf("Sheet %d, front: %d, Blank\n",i+1,frntb);
			}
			else{
				//do nothing
			}
			if(backa<=n && backb<=n){
				printf("Sheet %d, back : %d, %d\n",i+1,backa,backb);
			}
			else if(backa>n && backb<=n){
				printf("Sheet %d, back : Blank, %d\n",i+1,backb);
			}
			else if(backa<=n && backb>n){
				printf("Sheet %d, back : %d, Blank\n",i+1,backa);
			}
			else{
				//do nothing
			}
		}
	}
}