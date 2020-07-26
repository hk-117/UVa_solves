#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	string inp;
	deque<string> words;
	string wrd;
	while(getline(cin,inp),inp!="0"){
		inp+='\n';
		R(i,0,inp.size(),1){
			char c=inp[i];
			if(c>='A' && c<='Z' || c>='a' && c<='z'||c>='0' && c<='9'){
				wrd+=c;
			}
			else{
				if(wrd[0]>='0' && wrd[0]<='9'){
					int pos = atoi(wrd.c_str())-1;
					cout<< words[pos];
					string a=words[pos];
					words.erase(words.begin()+pos);
					words.push_front(a);
					wrd="";
					cout<<c;
				}
				else{
					if(wrd !="")
						words.push_front(wrd);
					cout<< wrd;
					wrd="";
					cout<<c;
				}
			}
		}
	}
}