#include<bits/stdc++.h>
#define R(i,a,b) for(int i=a;i<=b;i++)
#define R2(f,s,a,b) for(int f=a,s=b;f<s;++f,--s)
using namespace std;

void upsidedown(vector<vector<int>> &sqlt,int ring_no,int n){
	int startRow=ring_no,startCol=ring_no,endRow=n-1-ring_no,endCol=n-1-ring_no;
	R(i,startCol,endCol){
		if(i==startCol || i==endCol){
			R2(upper,lower,startRow,endRow){
				swap(sqlt[upper][i],sqlt[lower][i]);
			}
		}
		else{
			swap(sqlt[startCol][i],sqlt[endCol][i]);
		}
	}
}

void lrf(vector<vector<int>> &sqlt,int ring_no,int n){
	int startRow=ring_no,startCol=ring_no,endRow=n-1-ring_no,endCol=n-1-ring_no;
	R(i,startRow,endRow){
		if(i==startRow || i==endRow){
			R2(left,right,startCol,endCol){
				swap(sqlt[i][left],sqlt[i][right]);
			}
		}
		else{
			swap(sqlt[i][startCol],sqlt[i][endCol]);
		}
	}
}

void mdflip(vector<vector<int>> &sqlt,int ring_no,int n){
	int startRow=ring_no,startCol=ring_no,endRow=n-1-ring_no,endCol=n-1-ring_no;
	R(i,1,(endRow-startRow)){
		swap(sqlt[startRow][startCol+i],sqlt[startRow+i][startCol]);
		swap(sqlt[endRow][endCol-i],sqlt[endRow-i][endCol]);
	}
	swap(sqlt[startRow][endCol],sqlt[endRow][startCol]);
}

void mdiflip(vector<vector<int>> &sqlt,int ring_no,int n){
	int startRow=ring_no,startCol=ring_no,endRow=n-1-ring_no,endCol=n-1-ring_no;
	R(i,1,(endRow-startRow)){
		swap(sqlt[startRow][endCol-i],sqlt[startRow+i][endCol]);
		swap(sqlt[endRow][startCol+i],sqlt[endRow-i][startCol]);
	}
	swap(sqlt[startRow][startCol],sqlt[endRow][endCol]);
}

void print(vector<vector<int>> &sqlt,int n){
	R(i,0,n-1){
		R(j,0,n-1){
			if(j>0)
				cout<<" ";
			cout<<sqlt[i][j];
		}
		cout<<endl;
	}
}
int main(){
	int m;
	cin>>m;
	while(m--){
		int n;
		while(cin>>n){
			vector<vector<int>> sqlt(n,vector<int>(n));
			R(i,0,(n-1))
				R(j,0,(n-1))
					cin>>sqlt[i][j];
			int rings= (n+1)/2;
			R(i,0,rings-1){
				int T;
				cin>>T;
				while(T--){
					int choice;
					cin>>choice;
					if(choice==1){
						upsidedown(sqlt,i,n);
					}
					else if (choice==2){
						lrf(sqlt,i,n);
					}
					else if(choice==3){
						mdflip(sqlt,i,n);
					}
					else{
						mdiflip(sqlt,i,n);
					}
				}
			}
			print(sqlt,n);
		}
	}
}