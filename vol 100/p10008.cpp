#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool cmp(pair<char,int> a, pair<char,int> b){
	if(a.second > b.second)
		return true;
	else if(a.second == b.second){
		return a.first < b.first;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	cin.ignore();
	string inp;
	map<char,int> frqs;
	while(n--){
		getline(cin,inp);
		R(i,0,inp.size(),1){
			if(inp[i]>='a' && inp[i]<='z' || inp[i]>='A' && inp[i]<='Z'){
				char c=toupper(inp[i]);
				frqs[c]++;
			}
		}
	}
	vector<pair<char,int>> Data;
	for(auto it=frqs.begin();it!=frqs.end();it++){
		if(it->second >0)
			Data.push_back(make_pair(it->first,it->second));
	}
	sort(Data.begin(),Data.end(),cmp);
	for(auto it=Data.begin();it!=Data.end();it++){
		cout<< it->first <<" "<< it->second <<endl;
	}
}