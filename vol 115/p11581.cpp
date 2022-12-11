#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void kfog(vector<vector<int>> &grid){
	vector<vector<int>> inf=grid;
	grid[0][0]=(inf[0][1]+inf[1][0])%2;
	grid[0][1]=(inf[0][0]+inf[1][1]+inf[0][2])%2;
	grid[0][2]=(inf[0][1]+inf[1][2])%2;
	grid[1][0]=(inf[0][0]+inf[1][1]+inf[2][0])%2;
	grid[1][1]=(inf[0][1]+inf[1][0]+inf[1][2]+inf[2][1])%2;
	grid[1][2]=(inf[0][2]+inf[1][1]+inf[2][2])%2;
	grid[2][0]=(inf[1][0]+inf[2][1])%2;
	grid[2][1]=(inf[2][0]+inf[1][1]+inf[2][2])%2;
	grid[2][2]=(inf[2][1]+inf[1][2])%2;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<vector<int>> grid(3,vector<int>(3)),inf(3,vector<int>(3));
		R(i,0,3,1){
			string inp;
			cin>>inp;
			R(j,0,3,1){
				grid[i][j]=inp[j]-'0';
			}
		}
		int kof=0;
		if(grid==inf){
			cout<< -1<<endl;
		}
		else{
			while(1){
				inf=grid;
				kfog(grid);
				if(inf==grid){
					break;
				}
				else{
					kof++;
				}
			}
			
			cout<< kof-1 <<endl;
		}
		getchar();
	}
}
