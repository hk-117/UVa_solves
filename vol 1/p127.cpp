#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool matched(string a,string b){
    return a[0]==b[0]||a[1]==b[1];
}
void move(vector<stack<string>>&piles,int a,int b){
    piles[b].push(piles[a].top());
    piles[a].pop();
    if(piles[a].empty())
        piles.erase(piles.begin()+a,piles.begin()+a+1);
}

int main(){
    string line1,line2;
    while(getline(cin,line1),line1!="#"){
        vector<stack<string>> piles(52,stack<string>());
        getline(cin,line2);
        string tot=line1+" "+line2;
        stringstream ss(tot);
        string tmp;
        int tp=0;
        while(ss>>tmp){
            piles[tp++].push(tmp);
        }
        for (int i = 1; i < piles.size(); i++) {
		    if (i >= 3 && (matched(piles[i-3].top(),piles[i].top()))) {
				move(piles,i,i-3);
				i -= 4;
			}
			else if (i >= 1 && (matched(piles[i-1].top(),piles[i].top()))) {
				move(piles,i,i-1);
				i -= 2;
		    }
		}
        int siz = piles.size();
		cout << siz << " pile" << ((siz == 1) ? " " : "s ") << "remaining:";
		for (int i = 0; i < siz; i++)
			cout << " " << piles[i].size();
		cout << endl;
    }
}   
