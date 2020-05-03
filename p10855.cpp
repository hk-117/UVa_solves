#include <bits/stdc++.h>
#define R(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void rotate(vector<vector<char>> &v){
	int n=v.size();
	R(r,0,(n/2)){
		R(c,0,((n+1)/2)){
			char tmp=v[r][c];
			v[r][c]=v[n-1-c][r];
			v[n-1-c][r]=v[n-1-r][n-1-c];
			v[n-1-r][n-1-c]=v[c][n-1-r];
			v[c][n-1-r]=tmp;
		}
	}
}

void comp(vector<vector<char>> &V,vector<vector<char>> &v,vector<int> &cnt,int rt){
	int ed=v.size(),N=V.size();
	vector<vector<char>> ck(ed,vector<char>(ed));
	R(i,0,N-ed+1){
		R(j,0,N-ed+1){
			R(k,0,ed){
				ck[k].assign(V[i+k].begin()+j,V[i+k].begin()+j+ed);
			}
			if(ck==v){
				cnt[rt]++;
			}
		}
	}
}

int main(){
	int N,n;
	while(cin>>N>>n,N && n){
		vector<vector<char>> V(N,vector<char>(N)),v(n,vector<char>(n));
		R(i,0,N){
			R(j,0,N){
				cin>>V[i][j];
			}
		}
		R(i,0,n){
			R(j,0,n){
				cin>>v[i][j];
			}
		}
		vector<int>cnt(4,0);
		for(int i=0;i<4;i++){
			comp(V,v,cnt,i);
			rotate(v);
		}
		cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
	}
}