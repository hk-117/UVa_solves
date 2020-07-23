#include<bits/stdc++.h>
using namespace std;
int alph_ord(char c)
{
	if(isupper(c))
	{
		return (c-'A')*2;
	}
	else
	{
		return (c-'a')*2+1;
	}
}
bool fnc(const char &a,const char &b)
{
	return alph_ord(a) < alph_ord(b);
}
int main(){
    int nw;
    cin>>nw;
    while(nw--){
        string word;
        vector<string> all;
        cin>>word;
        sort(word.begin(),word.end(),fnc);
        string w=word;
        do{
            cout<<word<<endl;
            next_permutation(word.begin(),word.end(),fnc);
        }while(word!=w);
    }
}
