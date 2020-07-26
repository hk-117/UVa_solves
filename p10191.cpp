#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
int timeStamps[2000];
char line[257];
int main (){
	int n,dy=0;
	while (scanf("%d\n",&n)==1){
		dy++;
		if (n == 0){
		  printf ("Day #%d: the longest nap starts at 10:00 and will last for 8 hours and 0 minutes.\n", dy);
		}
		else{
			ms(timeStamps,0);
			timeStamps[1080] = 1;
			R(i,0,n,1){
				fgets(line,257,stdin);
				int h1,m1,h2,m2;
				sscanf (line, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
				int stTime = (h1 * 60) + m1;
				int enTime = (h2 * 60) + m2;
				R(j,stTime,enTime,1)
					if ((j >= 0) && (j <= 1080)) timeStamps[j] = 1;
			}
			int tm=600,mxNap=0,cntinuous=0,makeCount=1;
			R(i,600,1081,1){
				if (makeCount == 1){
					if (timeStamps[i] == 1){
						makeCount = 0;
						if (cntinuous > mxNap){
							mxNap = cntinuous;
							tm = i - cntinuous;
						}
					}
					else
						cntinuous++;
				}
				else{
					if (timeStamps[i] == 0){
						makeCount = 1;
						cntinuous = 1;
					}
				}
			}
			printf ("Day #%d: the longest nap starts at %02d:%02d and will last for ", dy, tm / 60, tm % 60);
			if (mxNap >= 60)
				printf ("%d hours and %d minutes.\n", mxNap / 60, mxNap % 60);
			else
				printf ("%d minutes.\n", mxNap);
		}
	}
}
