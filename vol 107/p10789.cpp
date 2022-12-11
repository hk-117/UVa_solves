#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool isPrime(int f){
	if(f==1)
		return false;
	for(int i=2;i*i<=f;i++)
		if(f%i==0)
			return false;
	return true;
}
int main(){
	int t,tc=0;
	cin>>t;
	while(t--){
		tc++;
		string s;
		cin>>s;
		map<char,int> frqs;
		R(i,0,s.size(),1){
			frqs[s[i]]++;
		}
		int emp=true;
		cout<<"Case "<<tc<<": ";
		for(auto it=frqs.begin();it!=frqs.end();it++){
			if(isPrime(it->second)){
				cout<< it->first;
				emp=false;
			}
		}
		if(emp){
			cout<<"empty"<<endl;
		}
		else
			cout<<endl;
	}
}