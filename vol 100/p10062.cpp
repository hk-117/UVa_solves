#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool cmp(pair<int,char> a,pair<int,char> b){
	if(a.first==b.first){
		return a.second > b.second;
	}
	else
		return a.first < b.first;
}
int main(){
	string line;
	bool pline=false;
	while(getline(cin,line)){
		if(pline)
			cout<<endl;
		pline=true;
		map<char,int> frq;
		R(i,0,line.size(),1){
			frq[line[i]]++;
		}
		vector<pair<int,char>> fq;
		for(auto it=frq.begin();it!=frq.end();it++){
			fq.push_back(make_pair(it->second,it->first));
		}
		sort(fq.begin(),fq.end(),cmp);
		for(auto it=fq.begin();it!=fq.end();it++){
			cout<< (int) it->second << " " << it->first <<endl;
		}
	}
}