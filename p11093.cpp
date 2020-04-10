#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,cs=0;
	cin>>t;
	while(t--){
		cs++;
		int n;
		cin>>n;
		vector<int>stations(n,0);
		vector<int>petrol(n,0);
		for(int i=0;i<n;i++){
			cin>>stations[i];
		}
		for(int i=0;i<n;i++){
			cin>>petrol[i];
		}
		int sum=0,diff=INT_MAX;
		for(int i=0;i<n;i++){
			sum+=stations[i]-petrol[i];
			diff=min(diff,sum);
		}
		if(sum<0){
			cout<<"Case "<<cs<<": Not possible\n";
		}
		else{
			int i;
			for(i=0;diff<0 && i<n;i++){
				diff =diff -(stations[i]-petrol[i]);
			}
			if(i==n){
				cout<<"Case "<<cs<<": Not possible\n";
			}
			else{
				cout<<"Case "<<cs<<": Possible from station "<< i+1 <<"\n";
			}
		}
		
		
	}
}