#include<bits/stdc++.h>
using namespace std;
int main(){
	int g;
	while(cin>>g,g!=0){
		string line;
		cin>>line;
		int len=line.size();
		g=len/g;
		for(auto it=line.begin();it!=line.end();it+=g)
			reverse(it,it+g);
		cout<<line<<endl;
	}
}