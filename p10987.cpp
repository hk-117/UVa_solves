#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	while(cin>>tc,tc!=0){
		vector<pair<string,string>> cards;
		string name,spel;
		int sz=tc;
		while(tc--){
			cin>>name>>spel;
			cards.push_back(make_pair(name,spel));
		}
		vector<string> sequence(sz,"");
		vector<bool> tracker(sz,false);
		int pos_diff,nxt=0,prev;
		for(auto it=cards.begin();it!=cards.end();it++){
			prev=nxt;
			nxt+= it->second.size() -1;
			pos_diff=nxt-prev;
			nxt=nxt%sz;
			for(int i=0;i<=pos_diff;i++){
				nxt=(prev+i)%sz;
				if(tracker[nxt])
					pos_diff++;
			}
			sequence[nxt]=it->first;
			tracker[nxt]=true;
		}
		for(auto it=sequence.begin();it!=sequence.end();it++){
			cout<<*it;
			if(it !=sequence.end()-1)
				cout<<" ";
		}
		cout<<endl;
	}
}