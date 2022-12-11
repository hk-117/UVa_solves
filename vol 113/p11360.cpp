#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void ch_row(vector<vector<int>> &mat,int a,int b,int n){
	R(i,0,n,1){
		swap(mat[a][i],mat[b][i]);
	}
}
void ch_col(vector<vector<int>> &mat,int a,int b,int n){
	R(i,0,n,1){
		swap(mat[i][a],mat[i][b]);
	}
}
void increment(vector<vector<int>> &mat,int n){
	R(i,0,n,1){
		R(j,0,n,1){
			mat[i][j]=(mat[i][j]+1)%10;
		}
	}
}
void decrement(vector<vector<int>> &mat,int n){
	R(i,0,n,1){
		R(j,0,n,1){
			mat[i][j]=(mat[i][j]-1)%10;
			if(mat[i][j]== -1){
				mat[i][j]+=10;
			}
		}
	}
}
void transpose(vector<vector<int>> &mat,int n){
	int ring=(n+1)/2;
	R(i,0,ring,1){
		int startrow=i,startcol=i,endrow=n-i-1,endcol=n-i-1;
		R(k,1,(endrow-startrow),1){
			swap(mat[startrow][startcol+k],mat[startrow+k][startcol]);
			swap(mat[endrow][endrow-k],mat[endrow-k][endcol]);
		}
		swap(mat[endrow][startcol],mat[startrow][endcol]);
	}
}

int main(){
	int t,tc=0;
	cin>>t;
	while(t--){
		tc++;
		int n;
		cin>>n;
		vector<vector<int>> mat(n,vector<int>(n));
		R(i,0,n,1){
		string dm;
		cin>>dm;
			R(j,0,n,1){
				mat[i][j]=dm[j]-'0';
			}
		}
		int m;
		cin>>m;
		while(m--){
			string command;
			cin>>command;
			if(command=="col"){
				int a,b;
				cin>>a>>b;
				ch_col(mat,a-1,b-1,n);
			}
			else if(command =="row"){
				int a,b;
				cin>>a>>b;
				ch_row(mat,a-1,b-1,n);
			}
			else if(command == "inc"){
				increment(mat,n);
			}
			else if(command =="dec"){
				decrement(mat,n);
			}
			else{
				transpose(mat,n);
			}
		}
		cout<<"Case #"<<tc<<endl;
		R(i,0,n,1){
			R(j,0,n,1){
				cout<<mat[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
