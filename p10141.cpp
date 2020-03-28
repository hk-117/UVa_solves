#include<bits/stdc++.h>

using namespace std;
int main(){
	int no_of_req, no_of_pro;
	string all_reqs;
	int rfp=0;
	while(cin>> no_of_req >> no_of_pro , no_of_req || no_of_pro){
		rfp++;
		double price=999999999.0;
		string name;
		int ticks=-1;

		for(int i=1;i<=no_of_req;i++){
			cin.ignore();
			getline(cin,all_reqs);
		}

		for(int i=1;i<=no_of_pro;i++){
			string nm;
			double pice;
			int tks;
			getline(cin,nm);
			cin>>pice>>tks;
			cin.ignore();
			if(tks>ticks){
				ticks=tks;
				name=nm;
				price=pice;
			}
			else if(tks==ticks){
				if(price>pice){
					price=pice;
					name=nm;
					ticks=tks;
				}
				else if(price==pice){
					name=name;
					ticks=ticks;
					price=price;
				}
			}
			for(int j=0;j<tks;j++){
				getline(cin,all_reqs);
			}
		}
		if (rfp > 1)
			cout << endl;

		cout<<"RFP #"<<rfp <<"\n";
		cout<< name <<"\n";
	}
}