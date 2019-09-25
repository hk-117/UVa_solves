#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v;
		int k;
		for(int i=0;i<n;i++){
			cin>>k;
			v.push_back(k);
		}
		sort(v.begin(),v.end());
		cout<<2*(v[n-1]-v[0])<<"\n";

	}
	return 0;

}
