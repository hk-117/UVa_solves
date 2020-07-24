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
    int inp;
	while(true){
        int cnt=0;
        vector<int> signals;
        while(cin>>inp,inp){
            signals.push_back(inp);
            cnt++;
        }
        if(!cnt && !inp){
            break;
        }
		int minimum= *min_element(signals.begin(),signals.end());
		minimum=2*minimum;
		vector<bool> status(signals.size(),false);
		while(!check_status(minimum,signals,status) && minimum<=18000){	
			minimum++;
		}
		if(minimum ==18001)
			puts("Signals fail to synchronise in 5 hours");
		else{
			int hs= minimum / 3600;
            int mn= (minimum%3600)/60;
            int s = (minimum%3600)%60;
            printf("%02d:%02d:%02d\n",hs,mn,s);
        }
    }
}
