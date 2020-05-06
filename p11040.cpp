#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<=b;i+=c)
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		vector<int> wall[9];
		R(i,0,8,1){
			wall[i].assign(i+1,0);
		}
		R(i,0,8,2){
			R(j,0,i,2){
				cin>>wall[i][j];
			}
		}
		R(i,0,6,2){
			R(j,0,(wall[i].size()),2){
				int diff=wall[i][j]-(wall[i+2][j]+wall[i+2][j+2]);
				diff/=2;
				wall[i+2][j+1]=diff;
				wall[i+1][j]=wall[i+2][j]+diff;
				wall[i+1][j+1]=wall[i+2][j+2]+diff;
			}
		}
		R(i,0,8,1){
			for(auto it=wall[i].begin();it !=wall[i].end();it++){
				cout<<*it;
				if(it != wall[i].end()-1)
					cout<<" ";
			}
			cout<<endl;
		}
	}
}
