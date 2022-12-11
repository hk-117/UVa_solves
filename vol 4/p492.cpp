#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool isVowel(char c){
	c= tolower(c);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return true;
	return false;
}
int main(){
	string line;
	while(getline(cin,line)){
		line+=" ";
		int sz= line.size();
		int stp = sz-1;
		string wrd;
		R(i,0,sz,1){
			if(line[i]>='a'&&line[i]<='z'||line[i]>='A'&&line[i]<='Z'){
				wrd+= line[i];
			}
			else{
				if(wrd.size()){
					if(isVowel(wrd[0]))
						wrd+="ay";
					else{
						char c=wrd[0];
						wrd.erase(wrd.begin());
						wrd+=c;
						wrd+="ay";
					}
				}
				cout<< wrd ;
				if(i < stp)
					cout<< line[i];
				wrd="";
			}
		}
		cout<<endl;
	}
}