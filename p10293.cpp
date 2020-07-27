#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int countLen(string &wrd){
	int wLen=0;
	R(j,0,wrd.size(),1){
		if((wrd[j]=='-') || (wrd[j]=='\''))
			continue;
		wLen++;
	}
	return wLen;
}
int main(){
	string line,text;
	bool brk=false;
	while(!brk){
		while(getline(cin,line),line[0]!='#'){
			if(!line.size()){
				brk=true;
				break;
			}
			if(text[text.size()-1]=='-'){
				text+=line;
			}
			else{
				text+=" "+line;
			}
		}
		if(brk)
			break;
		map<int,int> frqs;
		string wrd;
		text.erase(text.begin());
		text+=" ";
		R(i,0,text.size(),1){
			if(text[i]>='a'&&text[i]<='z'||text[i]>='A'&& text[i]<='Z'||text[i]=='-'||text[i]=='\''){
				wrd+=text[i];
			}
			else{
				if(wrd!=""){
					int wLen=countLen(wrd);
					frqs[wLen]++;
				}
				wrd="";
			}
		}
		for(auto it=frqs.begin();it!=frqs.end();it++){
			cout<< it->first <<" "<<it->second <<endl;
		}
		cout<<endl;
		text="";
	}
}