#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	while(cin>>n , n!=0){
		cin.ignore();
		vector<string>pic;
		string lin;
		while(n--){
			getline(cin,lin);
			pic.push_back(lin);
		}
		vector<int>spaces;
		int mini=count(pic[0].begin(),pic[0].end(),' ');
		spaces.push_back(mini);
		for(int i=1;i<pic.size();i++){
			int cnt=count(pic[i].begin(),pic[i].end(),' ');
			spaces.push_back(cnt);
			if(cnt<mini)
				mini=cnt;
		}
		int total_void=0;
		for(int i=0;i<pic.size();i++){
			total_void+=(spaces[i]-mini);
		}
		cout<<total_void<<endl;
	}
}