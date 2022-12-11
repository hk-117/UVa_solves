#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		char Name[85],Part[85];
		map<string,string> Parties;
		map<string,bool> Candidates;
		map<string,int> Votes;
		scanf("%d\n",&n);
		R(i,0,n,1){
			fgets(Name,sizeof(Name),stdin);
			Name[strlen(Name)-1]='\0';
			fgets(Part,sizeof(Part),stdin);
			Part[strlen(Part)-1]='\0';
			Parties[string(Name)]=Part;
			Candidates[string(Name)]=true;
		}
		int mx=0;
		string NM;
		scanf("%d\n",&m);
		R(i,0,m,1){
			fgets(Name,sizeof(Name),stdin);
			Name[strlen(Name)-1]='\0';
			if(Candidates[string(Name)]){
				Votes[string(Name)]++;
				if(mx < Votes[string(Name)]){
					mx=Votes[string(Name)];
					NM=Parties[string(Name)];
				}
			}
		}
		int cnt=0;
		for(auto it=Votes.begin();it!=Votes.end();it++){
			if(it->second == mx)
				cnt++;
		}
		if(cnt>1 || cnt==0){
			cout<<"tie"<<endl;
		}
		else{
			cout<<NM<<endl;
		}
		if(tc)
			cout<<endl;
	}
}