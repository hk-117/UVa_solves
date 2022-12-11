#include<bits/stdc++.h>
#define R(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){
	int w,h,n;
	while(cin>>w>>h>>n,w||h||n){
		vector<vector<bool>> board(w,vector<bool>(h));
		int xa,xb,ya,yb;
		while(n--){
			cin>>xa>>ya>>xb>>yb;
			if(xa>xb)
				swap(xa,xb);
			if(ya>yb)
				swap(ya,yb);
			R(i,(xa-1),(xb-1)){
				R(j,(ya-1),(yb-1)){
					if(!board[i][j])
						board[i][j]=true;
				}
			}
		}
		int emp=0;
		R(i,0,(w-1)){
			emp+=count(board[i].begin(),board[i].begin()+(h),0);
		}
		if(!emp){
			cout<<"There is no empty spots.\n";
		}
		else if(emp==1){
			cout<<"There is one empty spot.\n";
		}
		else{
			cout<<"There are "<<emp<<" empty spots.\n";
		}
		getchar();
	}
}