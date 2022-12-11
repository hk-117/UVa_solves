#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<string> coundex={
		"AEIOUHWY",
		"BFPV",
		"CGJKQSXZ",
		"DT",
		"L",
		"MN",
		"R"
	};
	string word;
	while(cin>>word){
		int prev=-1,i;
		string code;
		for(auto it=word.begin();it!=word.end();it++){
			for(i=0;i<7;i++){
				int pos=coundex[i].find(*it);
				if(pos !=string::npos)
					break;
			}
			if(i==0){
				code=code;
				prev=i;
			}
			else if(i==prev){
				code=code;
			}
			else{
				code+=to_string(i);
				prev=i;
			}
		}
		cout<<code<<endl;
	}
	
}