#include<iostream>
#include<cmath>
#include<cstdio>
#define preci 1E-9
using namespace std;
int p,q,r,s,t,u;
double fx(double x){
	double ans=(double)p*exp(-x)+(double) q*sin(x)+(double)r*cos(x)+(double)s*tan(x)+(double)t*x*x+(double)u;
	return ans;
}
int main(){
	while(cin>>p>>q>>r>>s>>t>>u){
		double a= fx(0.0),b=fx(1.0),x=0.0,y=1.0;
        if( a==0 ){
            printf("%.4lf\n",x);
        }
        else if(b==0){
            printf("%.4lf\n",y);
        }
        else if((a>0 && b<0) || (a<0 && b>0)){
			double rt= 1.0/2.0;
			double vl = fx(rt);
			while(fabs(vl)>preci){
				if(a>0 && vl>0 || a<0 && vl<0){
					x=rt;
				}
				else{
					y=rt;
				}
				rt= (x+y)/2.0;
				vl=fx(rt);
			}
			printf("%.4lf\n",rt);
		}
		else{
			puts("No solution");
		}
	}
}
