#include<bits/stdc++.h>
using namespace std;
int main(){
	int cs;
	cin>>cs;
	getchar();
	while(cs--){
		getchar();
		string indices,values;
		getline(cin,indices);
		
		vector<int> index;
		vector<string> val;
		
		char *tmp=new char[indices.size()+1];
		strcpy(tmp,indices.c_str());
		char *p=strtok(tmp," ");
		while(p!=0){
			int ind=atoi(p);
			index.push_back(ind);
			p=strtok(NULL," ");
		}
		
		getline(cin,values);
		
		char *tmp2=new char[values.size()+1];
		strcpy(tmp2,values.c_str());
		char *p2=strtok(tmp2," ");
		while(p2!=0){
			val.push_back(p2);
			p2=strtok(NULL," ");
		}
		vector<pair<int,string>> ar;
		for(int j=0;j<index.size();j++){
			ar.push_back(make_pair(index[j],val[j]));
		}
		sort(ar.begin(),ar.end());
		for(auto it=ar.begin();it!=ar.end();it++){
			cout<< it->second <<endl;
		}
		if(cs)
			cout<<endl;
	}
}