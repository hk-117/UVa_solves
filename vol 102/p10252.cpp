#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	string linea,lineb;
	while(getline(cin,linea)){
		getline(cin,lineb);
		map<char,int> alph[2],seq;
		int sz[2];
		sz[0]=linea.size(),sz[1]=lineb.size();
		R(i,0,sz[0],1){
			alph[0][linea[i]]++;
		}
		R(i,0,sz[1],1){
			alph[1][lineb[i]]++;
		}
		bool maxa=true;
		if(sz[0]<sz[1]){
			maxa=false;
		}
		for(auto it=alph[maxa].begin();it!=alph[maxa].end();it++){
			if(alph[!maxa].find(it->first) != alph[!maxa].end()){
				seq[it->first]= min(it->second,alph[!maxa][it->first]);
			}
		}
		for(auto it=seq.begin();it!=seq.end();it++){
			R(i,1,it->second+1,1){
				cout<< it->first;
			}
		}
		cout<<endl;
	}
}