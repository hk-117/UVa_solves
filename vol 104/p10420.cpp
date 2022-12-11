#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string line,country;
	cin>>n;
	cin.ignore();
	map<string,int> Lis;
	while(n--){
		getline(cin,line);
		stringstream ss(line);
		ss>>country;
		Lis[country]++;
	}
	for(auto it=Lis.begin();it!=Lis.end();it++){
		cout<< it->first <<" "<< it->second <<endl;
	}
}