#include<bits/stdc++.h>
using namespace std;
int main(){
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		string word;
		int w=0;
		while(ss>>word){
			if(w++)
				printf(" ");
			for(int i=word.size()-1;i>=0;i--)
				putchar(word[i]);
		}
		puts("");
	}
}