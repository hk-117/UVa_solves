#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<char>> &a,int n){
	for(int i=0;i<n/2;i++){
		for(int j=0;j<(n+1)/2;j++){
			int tmp=a[i][j];
			a[i][j]=a[n-1-j][i];
			a[n-1-j][i]=a[n-1-i][n-1-j];
			a[n-1-i][n-1-j]=a[j][n-1-i];
			a[j][n-1-i]=tmp;
		}
	}
}

void reflect(vector<vector<char>> &a,int n){
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n;j++){
			swap(a[i][j],a[n-1-i][j]);
		}
	}
}
int main(){
	int n,t=0;
	while(cin>>n){
		t++;
		vector<vector<char>> a(n,vector<char>(n)),b(n,vector<char>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
			cin.ignore();
			for(int j=0;j<n;j++){
				cin>>b[i][j];
			}
		}
		int rotations=0,reflections=0;
		while(reflections<2){
			while(rotations<4){
			    if(a==b)
                    break;
                rotate(a,n);
				rotations++;
			}
		    if(a==b)
                break;
            rotations=0;
			reflect(a,n);
			reflections++;
		}
		cout<<"Pattern "<<t<<" was ";
		if(reflections==0){
			if(rotations==0){
				cout<<"preserved."<<endl;
			}
			else{
				cout<<"rotated "<<90*rotations<<" degrees."<<endl;
			}
		}
		else{
			if(reflections==2 && rotations==0){
				cout<<"improperly transformed."<<endl;
			}
			else if(rotations<4 && rotations !=0 && reflections<2){
				cout<<"reflected vertically and rotated "<<90*rotations<<" degrees."<<endl;
			}
			else{
				cout<<"reflected vertically."<<endl;
			}
		}
		
	}
}
