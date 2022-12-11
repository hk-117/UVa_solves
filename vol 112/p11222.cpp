#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,tc=0;
	cin>>t;
	while(t--){
		tc++;
		vector<pair<int,vector<int>>> friends(3);
		for(int i=0;i<3;i++){
			int tmp;
			cin>>tmp;
			friends[i].first=i+1;
			set<int> vals;
			for(int j=0;j<tmp;j++){
				int inp;
				cin>>inp;
				vals.insert(inp);
			}
			friends[i].second.assign(vals.begin(),vals.end());
		}
		for(auto it=friends[0].second.begin();it!=friends[0].second.end();it++){
			auto pos=find(friends[1].second.begin(),friends[1].second.end(),*it);
			auto pos2=find(friends[2].second.begin(),friends[2].second.end(),*it);
			if(pos !=friends[1].second.end() || pos2 !=friends[2].second.end()){
				if(pos !=friends[1].second.end())
					friends[1].second.erase(pos);
				if(pos2 !=friends[2].second.end())
					friends[2].second.erase(pos2);
				friends[0].second.erase(it);
				it--;
			}
		}
		for(auto it=friends[1].second.begin();it!=friends[1].second.end();it++){
			auto pos2=find(friends[2].second.begin(),friends[2].second.end(),*it);
			if(pos2 !=friends[2].second.end()){
				friends[2].second.erase(pos2);
				friends[1].second.erase(it);
				it--;
			}
		}
		vector<int> len(3,0);
		len[0]=friends[0].second.size();
		len[1]=friends[1].second.size();
		len[2]=friends[2].second.size();
		auto maxe=max_element(len.begin(),len.end());
		cout<<"Case #"<<tc<<":\n";
		for(int i=0;i<3;i++){
			if(len[i]==*maxe){
				sort(friends[i].second.begin(),friends[i].second.end());
				cout<<i+1<<" "<<len[i];
				for(int j=0;j<len[i];j++){
					cout<<" ";
					cout<<friends[i].second[j];
				}
				cout<<endl;
			}
		}
	}
}