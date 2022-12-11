#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	map<int,map<char,int>> D;
	string inp;
	int k=1;
	while(cin>>inp,inp!="#"){
		R(i,0,inp.size(),1){
			D[k][inp[i]]++;
		}
		k++;
	}
	cin.ignore();
	while(getline(cin,inp),inp!="#"){
		stringstream ss(inp);
		char c;
		map<char,int> wf;
		while(ss>>c){
			wf[c]++;
		}
		int psbl=0;
		for(auto it=D.begin();it!=D.end();it++){
			bool possible=true;
			for(auto jt=it->second.begin();jt!=it->second.end();jt++){
				if(wf.find(jt->first) == wf.end()){
					possible=false;
					break;
				}
				else if( wf[jt->first] < jt->second){
					possible=false;
					break;
				}
				else{
					//Do nothing
				}
			}
			if(possible)
				psbl++;
		}
		cout<< psbl <<endl;
	}
}