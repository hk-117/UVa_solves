#include<bits/stdc++.h>
using namespace std;
int main(){
	int samples;
	while(cin>>samples,samples){
		vector<int> magnitudes;
		for(int i=1;i<=samples;i++){
			int tmp;
			cin>>tmp;
			magnitudes.push_back(tmp);
		}
		int peaks=0;
		bool up=false,down=false;
		if(magnitudes[samples-1]<magnitudes[0])
			up=true;
		else
			down=true;
		magnitudes.push_back(magnitudes[0]);
		for(int i=1;i<=samples;i++){
			if((magnitudes[i-1]<magnitudes[i]) && down){
				peaks++;
				down=false;
				up=true;
			}
			else if((magnitudes[i-1]> magnitudes[i]) && up){
				peaks++;
				up=false;
				down=true;
			}
		}
		cout<<peaks<<endl;
	}
}