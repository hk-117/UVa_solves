#include<bits/stdc++.h>
using namespace std;
bool validChar(int nm){
	if(nm>='a' && nm<='z' || nm>='A' && nm<='Z' || nm==' '||nm=='!'||nm==','||nm=='.'||nm==':'||nm==';'||nm=='?'){
		return true;
	}
	return false;
}
void encode(string msg){
	for(int i=msg.size()-1;i>=0;i--){
		int asci= (int) msg[i];
		string st= to_string(asci);
		reverse(st.begin(),st.end());
		cout<<st;
	}
	cout<<endl;
}
void decode(string spy){
	int len=0;
	string dm;
	for(int i=spy.size()-1;i>=0;i--){
		if(len<3){
			dm+= spy[i];
			len++;
		}
		if(len==2){
			int nm= atoi(dm.c_str());
			if(validChar(nm)){
				cout<< (char) nm ;
				dm="";
				len=0;
			}
		}
		else if(len==3){
			int nm= atoi(dm.c_str());
			cout<< (char) nm;
			dm="";
			len=0;
		}
	}
	cout<<endl;
}
int main(){
	string line;
	while(getline(cin,line)){
		if(line[0]>='0' && line[0] <='9')
			decode(line);
		else
			encode(line);
	}
}