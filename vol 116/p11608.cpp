#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,cs=0;
	while(cin>>t,t>= 0){
		cs++;
		vector<int> c(13),r(13);
		int total=0;
		c[0]=t;
		for(int i=1;i<=12;i++){
			cin>>c[i];
		}
		for(int i=0;i<12;i++){
			cin>>r[i];
		}
		cout<<"Case "<<cs<<":\n";
		for(int i=0;i<12;i++){
			total+=c[i];
			if(total>=r[i]){
				cout<<"No problem! :D\n";
				total-=r[i];
			}
			else{
				cout<<"No problem. :(\n";
			}
		}
	}
}