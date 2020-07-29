#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef unsigned long long ull;
int main(){
	int t;
	cin>>t;
	while(t--){
		map<char,map<char,int>> Rules;
		int r;
		cin>>r;
		string ln;
		char c,s[105];
		R(i,0,r,1){
			cin>> ln;
			sscanf(ln.c_str(),"%c -> %s",&c,s);
			int ls=strlen(s);
			R(j,0,ls,1){
				Rules[c][s[j]]++;
			}
		}
		int q;
		cin>>q;
		map<char,ull> ifrq,ofrq;
		R(i,0,q,1){
			string initial;
			char fiq;
			int n;
			unsigned long long tf=0;
			cin>>initial>>fiq>>n;
			R(j,0,initial.size(),1){
				ifrq[initial[j]]++;
			}
			R(j,0,n,1){
				ofrq.clear();
				for(auto it=ifrq.begin();it!=ifrq.end();it++){
					if(it->second > 0){
						if(Rules.find(it->first) != Rules.end()){
							ofrq[it->first] = it->second;
							it->second = 0;
						}
					}
				}
				for(auto it=ofrq.begin();it!=ofrq.end();it++){
					for(auto rl= Rules[it->first].begin();rl!=Rules[it->first].end();rl++){
						ifrq[rl->first]+=ofrq[it->first] * rl->second;
					}
				}
			}
			cout<< ifrq[fiq] <<endl;
			ifrq.clear();
			ofrq.clear();
		}
	}
}