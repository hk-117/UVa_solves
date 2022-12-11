#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	int tc;
	cin>>tc;
	cin.ignore();
	while(tc--){
		string inp;
		getline(cin,inp);
		map<char,int> frq;
		int mx=0;
		R(i,0,inp.size(),1){
			char c= tolower(inp[i]);
			if(c>='a' && c<='z'){
				frq[c]++;
				mx=max(frq[c],mx);
			}
		}
		for(auto it=frq.begin();it!=frq.end();it++){
			if(it->second == mx)
				cout<< it->first;
		}
		cout<<endl;
	}
}