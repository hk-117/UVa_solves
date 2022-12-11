#include<bits/stdc++.h>
using namespace std;

int main(){
	int m;
	cin>>m;
	getchar();
	while(m--){
		int n,k;
		cin>>n>>k;
		vector<bool> coin_status(n,0);
		while(k--){
			int cits;
			char eq;
			cin>>cits;
			vector<int> c;
			for(int i=0;i<2*cits;i++){
				int tmp;
				cin>>tmp;
				c.push_back(tmp);
			}
			cin>>eq;
			if(eq == '='){
				for(int i=0;i<c.size();i++){
					coin_status[c[i]-1]=1;
				}
			}
			else{
				for(int i=1;i<=n;i++){
					auto it=find(c.begin(),c.end(),i);
					if(it ==c.end()){
						coin_status[i-1]=1;
					}
				}
			}
		}
		if(count(coin_status.begin(),coin_status.end(),0)==1){
			auto it=find(coin_status.begin(),coin_status.end(),0);
			cout<<it-coin_status.begin()+1 <<endl;
		}
		else{
			cout<<0<<endl;
		}
		if(m)
			cout<<endl;
		getchar();
	}
}