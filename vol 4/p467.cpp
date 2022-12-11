#include<bits/stdc++.h>
using namespace std;
bool check_status(int minimum,vector<int> &signals,vector<bool> &status){
	for(int i=0;i<status.size();i++){
		if(minimum%(signals[i]*2) >=(signals[i]-5))
			status[i]=false;
		else
			status[i]=true;
	}
	if(count(status.begin(),status.end(),1)!=status.size())
		return false;
	else
		return true;
}


int main(){
	string signal_set;
	int tst=0;
	while(getline(cin,signal_set)){
		tst++;
		vector<int> signals;
		char *tmp=new char[signal_set.size()+1];
		strcpy(tmp,signal_set.c_str());
		char *p=strtok(tmp," ");
		while(p!=0){
			int sig=atoi(p);
			signals.push_back(sig);
			p=strtok(NULL," ");
		}
		int minimum= *min_element(signals.begin(),signals.end());
		minimum=2*minimum;
		vector<bool> status(signals.size(),false);
		while(!check_status(minimum,signals,status) && minimum<=3600){	
			minimum++;
		}
		if(minimum ==3601)
			cout<<"Set "<<tst<<" is unable to synch after one hour.\n";
		else
			cout<<"Set " <<tst<< " synchs again at "<<(minimum)/60<< " minute(s) and "<<(minimum%60)<<" second(s) after all turning green.\n";
	}
}