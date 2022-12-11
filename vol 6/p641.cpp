#include<bits/stdc++.h>
using namespace std;
int pos[1005]={-1};
char sq[]="_abcdefghijklmnopqrstuvwxyz.";
void createMap(void){
	for(int i=0;i<28;i++){
		pos[(int)sq[i]]=i;
	}
}
int main(){
	createMap();
	int k;
	string msg;
	while(cin>>k,k){
		cin>>msg;
		int n=msg.size();
		string dc=msg;
		for(int i=0;i<n;i++){
			dc[(k*i)%n] = sq[(pos[msg[i]]+i)%28];
		}
		cout<<dc<<endl;
	}
}