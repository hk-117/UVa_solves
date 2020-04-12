#include<bits/stdc++.h>
using namespace std;
bool cmp (pair<int,int> &a, pair<int,int> &b){
	return a.second<b.second;
}
int main(){
	int n;
	while(cin>>n,n!=0){
		vector<pair<int,int>> cd;
		int c,p;
		for(int i =0;i<n;i++){
			cin>>c>>p;
			cd.push_back(make_pair(c,p));
		}
		for(int i=0;i<n;i++){
			cd[i].second = i+1+cd[i].second;
		}
		sort(cd.begin(),cd.end(),cmp);
		cd.push_back(cd[0]);
		bool possible=true;
		for(int i=0;i<n;i++){
			if(abs(cd[i].second)>n || cd[i].second <=0)
				possible=false;
			else if(cd[i].second ==cd[i+1].second)
				possible=false;
		}
		if(!possible)
			cout<<"-1"<<endl;
		else{
			for(auto it=cd.begin();it!=cd.end()-1;it++){
				cout<< it->first;
				if(it != cd.end()-2)
					cout<<" ";
			}
			cout<<endl;
		}
	}
}