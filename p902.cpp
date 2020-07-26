#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	int n;
	while(cin>>n){
		string msg,inp;
		map<string,int> frqs;
		int mx=0,j=0;
		cin>>inp;
		R(i,0,inp.size(),1){
			msg+=inp[i];
			if(i+1 >=n){
				string pass(msg.begin()+j,msg.begin()+j+n);
				frqs[pass]++;
				mx=max(mx,frqs[pass]);
				j++;
			}
		}
		for(auto it=frqs.begin();it!=frqs.end();it++){
			if(it->second == mx){
				cout<< it->first <<endl;
				break;
			}
		}
	}
}