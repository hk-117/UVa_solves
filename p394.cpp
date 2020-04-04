#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,R;
	cin>>N>>R;
	map<string,pair<int,vector<int>>> ar;
	while(N--){
		string name;
		int base,siz,dim;
		vector<int>lower,upper,cs;
		cin>>name>>base>>siz>>dim;
		cs.push_back(siz);
		int tmp;
		for(int i=1;i<=2*dim;i++){
			cin>>tmp;
			if(i%2==0){
				upper.push_back(tmp);
			}
			else{
				lower.push_back(tmp);
			}
		}
		reverse(lower.begin(),lower.end());
		reverse(upper.begin(),upper.end());
		for(int i=0;i<dim-1;i++){
			int c;
			c=cs[i]*(upper[i]-lower[i]+1);
			cs.push_back(c);
		}
		int c0=base;
		for(int i=0;i<cs.size();i++){
			c0 -=(cs[i]*lower[i]);
		}
		cs.push_back(c0);
		reverse(cs.begin(),cs.end());
		ar[name].first=dim;
		ar[name].second=cs;
	}
	while(R--){
		string name;
		cin>>name;
		vector<int>indices;
		int dimen=ar[name].first,address;
		while(dimen--){
			int tm;
			cin>>tm;
			indices.push_back(tm);
		}
		dimen=ar[name].first;
		cout<<name<<"[";
		for(int i=0;i<dimen;i++){
			if(i==0){
				if(i!=indices.size()-1)
					cout<<indices[i]<<", ";
				else
					cout<<indices[i]<<"] = ";
			}
			else if(i==dimen-1){
				cout<<indices[i]<<"] = ";
			}
			else
				cout<<indices[i]<<", ";
		}
		address=ar[name].second[0];
		for(int i=1;i<=dimen;i++){
			address+=ar[name].second[i]*indices[i-1];
		}
		cout<<address<<endl;
	}
}
