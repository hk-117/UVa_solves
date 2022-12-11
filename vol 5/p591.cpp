#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,s=0;
	while(cin>>n,n!=0){
		s++;
		vector<int>bricks;
		int sum=0;
		for(int i=1;i<=n;i++){
			int tmp;
			cin>>tmp;
			bricks.push_back(tmp);
			sum+=tmp;
		}
		int avg=sum/n,diff_sum=0;
		for(int i=0;i<n;i++){
			diff_sum+=abs(bricks[i]-avg);
		}
		cout<<"Set #"<<s<<endl;
		cout<<"The minimum number of moves is "<<diff_sum/2<<".\n\n";
	}
}
