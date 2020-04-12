#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n,n!=0){
		vector<bool> stations(1423,false);
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			stations[tmp]=true;
		}
		int i=0;
		while(i<=1322){
			bool possible=false;
			for(int j=i+1;j<=i+200 && j<=1422;j++){
				if(stations[j]){
					i=j;
					possible=true;
					break;
				}
			}
			if(!possible){
				cout<<"IMPOSSIBLE\n";
				break;
			}
			else if((i+100 >=1422)){
				cout<<"POSSIBLE\n";
				break;
			}
			
			
		}
	}
}