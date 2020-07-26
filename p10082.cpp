#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
string keyBoard="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
map<char,int> poses;
void makePos(){
	R(i,0,keyBoard.size(),1){
		poses[keyBoard[i]]=i;
	}
}
int main(){
	makePos();
	string line;
	while(getline(cin,line)){
		R(i,0,line.size(),1){
			if(line[i]!=' ')
				line[i]= keyBoard[poses[line[i]]-1];
		}
		cout<<line<<endl;
	}
}