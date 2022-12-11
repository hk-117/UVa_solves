#include<bits/stdc++.h>
using namespace std;

void checkerror(vector<vector<int>> &mt,int &ercolpos,int &errowpos,int &rowerr,int &colerr,int n){
		for(int i=0;i<n;i++){
			int rowcount=0;
			for(int j=0;j<n;j++){
				if(mt[i][j])
					rowcount++;
			}
			if(rowcount%2 !=0){
				errowpos=i;
				rowerr++;
			}
		}
		for(int i=0;i<n;i++){
			int colcount=0;
			for(int j=0;j<n;j++){
				if(mt[j][i])
					colcount++;
			}
			if(colcount%2 !=0){
				ercolpos=i;
				colerr++;
			}
		}
}

int main(){
	int n;
	while(cin>>n,n){
		vector<vector<int>> mt(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>mt[i][j];
		int ercolpos,errowpos,rowerr=0,colerr=0;
		checkerror(mt,ercolpos,errowpos,rowerr,colerr,n);
		if((!rowerr) && (!colerr)){
			cout<<"OK\n";
		}
		else if(rowerr==1 && colerr==1){
            cout<<"Change bit ("<< errowpos+1 <<","<< ercolpos+1 <<")\n";
		}
		else
			cout<<"Corrupt\n";
		
	}
}
