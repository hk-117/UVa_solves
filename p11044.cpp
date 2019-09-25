#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int a,b,res;
	while(t--){
		cin>>a>>b;

		a=a/3;
		b=b/3;
		res=a*b;
		cout<<res<<"\n";
	}
	return 0;
}
