#include <cmath>
#include <cstdio>
using namespace std;

double stockPrice(int p, int a, int b, int c, int d,int k){
    double price = 0.0;
    price = p * (sin(a * k + b) + cos(c * k + d) + 2);
    return price;
}

int main(){
	int p,a,b,c,d,n;
	while(scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6){
		double prev = 0;
        double mxUp = 0;
        double mnDown = 0;
        double mxDiff = 0;
        double price;
        for(int i=1;i<=n;i++){
          price = stockPrice(p, a, b, c, d, i);
          if(price < prev){
            double preDiff = mxUp - price;
            double nwDiff = prev - price;
            if(nwDiff > mxDiff){
              mxDiff = nwDiff;
              mxUp = prev;
              mnDown = price;
            }
            if(preDiff > mxDiff){
              mxDiff = preDiff;
              mnDown = price;
            }
          }else{
            if(mxUp < price){
              mxUp = price;
            }
            prev = price;
          }
        }
        if(mnDown <= 0){
          printf("0.00\n");
        }else{
          printf("%.6f\n",mxDiff);
        }
	}
}