#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string>DT={"0123456789","-","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
	int dset;
	cin>>dset;
	getchar();
	while(dset--){
		int dts;
		cin>>dts;
		vector<string>directories;
		string tmp;
		while(dts--){
			cin>>tmp;
			string to_pos;
			for(auto it=tmp.begin();it !=tmp.end();it++){
				int pos,i;
				for(i=0;i<10;i++){
					pos=DT[i].find(*it);
					if(pos!=string::npos)
						break;
				}
				if(!i){
					to_pos+=*it;
				}
				else if(i==1){
					continue;
				}
				else{
					to_pos+=to_string(i);
				}
			}
			to_pos.insert(3,"-");
			directories.push_back(to_pos);
		}
		map<string,int> counting;
		for(auto it=directories.begin(); it!=directories.end(); it++){
			counting[*it]+=1;
		}
		int tracker=1;
		for(auto it=counting.begin();it!=counting.end();it++){
			if(it->second >1){
				cout<< it->first <<" "<< it->second<<endl;
				tracker=it->second;
			}
		}
		if(tracker==1)
			cout<<"No duplicates.\n";
		if(dset)
			cout<<endl;
		getchar();
	}
}