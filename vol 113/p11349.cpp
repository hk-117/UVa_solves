#include<bits/stdc++.h>
typedef long long ll;
#define R(i,a,b,c) for(ll i=a;i<b;i+=c)
using namespace std;
bool check_rest(vector<vector<ll>> &sm, int col,int n){
	int rows=n/2;
	R(i,0,rows,1){
		if(sm[i][col]<0 || sm[n-1-i][col]<0 || sm[i][col]!=sm[n-1-i][col]){
			return false;
		}
	}
	return true;
}
bool check_all(vector<vector<ll>> &sm, int st,int en,int n){
	R(i,0,n,1){
			if(sm[i][st]< 0 || sm[n-i-1][en]< 0 || sm[i][st] != sm[n-i-1][en]){
				return false;
			}
	}
	return true;
}
int main(){
	int t,tc=0;
	cin>>t;
	while(t--){
		tc++;
		ll n;
		string dm;
		cin>>dm>>dm>>n;
		vector<vector<ll>> sm(n,vector<ll>(n));
		R(i,0,n,1){
			R(j,0,n,1){
				cin>>sm[i][j];
			}
		}
		int rings=n/2;
		bool sym=true;
		R(i,0,rings,1){
			sym=check_all(sm,i,n-1-i,n);
			if(!sym){
				break;
			}
		}
		if(sym && n%2==1){
			sym=check_rest(sm,(n/2),n);
			if(sm[n/2][n/2]<0){
				sym=false;
			}
		}
		if(!sym){
			cout<<"Test #"<<tc<<": Non-symmetric.\n";
		}
		else{
			cout<<"Test #"<<tc<<": Symmetric.\n";
		}
	}
}
