#include<bits/stdc++.h>
using namespace std;
int lf[100005],rt[100005];
int main(){
	int s,b;
	while(cin>>s>>b, s||b){
		for(int i=1;i<=s;i++){
			lf[i]=i-1;
			rt[i]=i+1;
		}
		lf[1]=-1;
		rt[s]=-1;
		for(int i=1;i<=b;i++){
			int l,r;
			cin>>l>>r;
			rt[lf[l]]=rt[r];
			lf[rt[r]]=lf[l];
			if(lf[l] == -1){
				cout<<"* ";
			}
			else{
				cout<< lf[l] <<" ";
			}
			if(rt[r] == -1){
				cout<<"*"<<endl;
			}
			else{
				cout<< rt[r] <<endl;
			}
		}
		cout<<"-"<<endl;
	}
}