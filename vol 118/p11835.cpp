#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
	int gprix,pilots;
	while(cin>>gprix>>pilots, gprix && pilots){
		vector<vector<int>> races(gprix,vector<int>(pilots));
		R(i,0,gprix,1){
			R(j,0,pilots,1){
				cin>>races[i][j];
			}
		}
		int scsys;
		cin>>scsys;
		while(scsys--){
			vector<int> total(pilots,0),scores(pilots,0);
			int poses;
			cin>>poses;
			R(i,0,poses,1){
				cin>>scores[i];
			}
			R(i,0,gprix,1){
				R(j,0,pilots,1){
					total[j] += scores[races[i][j]-1];
				}
			}
			auto champ=max_element(total.begin(),total.end());
			int cnt= count(total.begin(),total.end(), *champ);
			int spaces=0;
			R(i,0,pilots,1){
				if(total[i]== *champ){
					cout<< i+1;
					spaces++;
					if(spaces != cnt){
						cout<<" ";
					}
				}
			}
			cout<<endl;
		}
	}
}
