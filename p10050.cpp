#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int>hartal_params;
		int parties,days;
		cin>>days>>parties;
		vector<bool>waste(days+1,false);
		while(parties--){
			int tmp;
			cin>>tmp;
			hartal_params.push_back(tmp);
		}
		for(auto it=hartal_params.begin();it!=hartal_params.end();it++){
			for(int i=*it; i<=days;i=i+(*it)){
				if(i%7 ==0 || i%7==6)
					continue;
				else
					waste[i]=true;
			}
		}
		cout<<count(waste.begin(),waste.end(),true)<<endl;
	}
}