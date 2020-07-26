#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct schedule{
	int stInMins,endInMins;
}AppointMents[105];
bool cmp(schedule a,schedule b){
	return a.stInMins<b.stInMins;
}
int main(){
	int n,dy=0;
	while(cin>>n){
		cin.ignore();
		dy++;
		string apmnt;
		AppointMents[0].stInMins=600;
		AppointMents[0].endInMins=600;
		AppointMents[n+1].stInMins=1080;
		AppointMents[n+1].endInMins=1080;
		R(i,1,n+1,1){
			getline(cin,apmnt);
			int stMin,h1,m1,h2,m2,enMin;
			sscanf(apmnt.c_str(),"%d:%d %d:%d",&h1,&m1,&h2,&m2);
			AppointMents[i].stInMins=h1*60+m1;;
			AppointMents[i].endInMins=h2*60+m2;;
		}
		sort(AppointMents,AppointMents+n+2,cmp);
		int mxNap= 0;
		int stNap=600;
		R(i,1,n+2,1){
			int diff= AppointMents[i].stInMins-AppointMents[i-1].endInMins;
			if(mxNap<diff){
				stNap=AppointMents[i-1].endInMins;
				mxNap=diff;
			}
		}
		printf("Day #%d: the longest nap starts at %d:%02d and will last for ",dy,stNap/60,stNap%60);
		if(mxNap<60)
			printf("%d minutes.\n",mxNap);
		else
			printf("%d hours and %d minutes.\n",mxNap/60,mxNap%60);
		
	}
}