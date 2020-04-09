#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		vector<int> seq;
		vector<bool> ache(n-1,false);
		int k=n;
		while(k--){
			int tmp;
			cin>>tmp;
			seq.push_back(tmp);
		}
		if(n==1)
			cout<<"Jolly"<<endl;
		else{
			for(auto it=seq.begin();it!=seq.end()-1;it++){
				int diff =abs(*it - *(it+1));
				if(diff>=1 && diff <= n-1)
					ache[diff-1]=true;
			}
			if(count(ache.begin(),ache.end(),true)==n-1)
				cout<<"Jolly"<<endl;
			else
				cout<<"Not jolly"<<endl;
		}
	}
}