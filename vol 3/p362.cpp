#include<bits/stdc++.h>
using namespace std;
int main(){
	int fSize,tc=0;
	while(cin>>fSize,fSize){
		tc++;
		int nByt,dlByt=0,tTime=0,tdlByt=0;
		printf("Output for data set %d, %d bytes:\n",tc,fSize);
		while(tdlByt<fSize){
			cin>>nByt;
			dlByt+=nByt;
			tdlByt+=nByt;
			tTime++;
			if(!(tTime%5)){
				printf("   Time remaining: ");
				if(dlByt==0){
					puts("stalled");
				}
				else{
					int rem= fSize-tdlByt;
					int rmSec= (int)ceil((rem*5.0)/dlByt);
					printf("%d seconds\n",rmSec);
					dlByt=0;
				}
			}
		}
		printf("Total time: %d seconds\n",tTime);
		puts("");
	}
}