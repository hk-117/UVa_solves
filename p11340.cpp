#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int k;
		cin>>k;
		map<char,int> dam;
		for(int i=0;i<k;i++){
			char nm;
			int val;
			cin>>nm>>val;
			dam[nm]=val;
		}
		int m;
		cin>>m;
		int total=0;
		m++;
		while(m--){
			string line;
			getline(cin,line);
			for(auto it=line.begin();it!=line.end();it++){
				total+=dam[*it];
			}
		}
		cout<<setprecision(2)<<fixed<<total/100.0<<"$"<<endl;
	}
}