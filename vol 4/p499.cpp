#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	string inp;
	while(getline(cin,inp)){
		map<char,int> frqs;
		int mx=0;
		R(i,0,inp.size(),1){
			if(inp[i]>='a' && inp[i]<='z'|| inp[i]>='A' && inp[i]<='Z'){
				frqs[inp[i]]++;
				mx=max(frqs[inp[i]],mx);
			}
		}
		for(auto it=frqs.begin();it!=frqs.end();it++){
			if(it->second == mx){
				cout<< it->first;
			}
		}
		cout<<" "<<mx<<endl;
	}
}