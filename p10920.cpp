#include<bits/stdc++.h>
#define R(i,a,b) for(long long i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int main(){
	ll sz,p;
	while(cin>>sz>>p,sz && p){
		ll ringstart=sqrt(p);
		if(ringstart%2==0){
			ringstart-=1;
		}
		ll ringend=ringstart+2;
		ll ringstartsq=ringstart*ringstart;
		ll pos=(sz+1)/2,st=1;
		while(st*st<ringstartsq){
			pos+=1;
			st+=2;
		}
		ll ringendsq=ringend*ringend;
		ll diff=(ringendsq-ringstartsq)/4;
		ll x=pos,y=pos,total=ringstartsq;
		if(p!=ringstartsq){
			x++;
			total++;
		}
		bool done=false;
		if(x>sz){
			x=sz;
			y=sz;
			done=true;
		}
		if(!done){
			R(i,1,diff-1){
				if(total==p){
					done=true;
					break;
				}
				total+=1;
				y--;
			}
		}
		
		if(!done){
				R(i,1,diff){
				if(total==p){
					done=true;
					break;
				}
				total+=1;
				x--;
			}
		}
		
		if(!done){
			R(i,1,diff){
				if(total==p){
					done=true;
					break;
				}
				total+=1;
				y++;
			}
		}		
		if(!done){
			R(i,1,diff){
				if(total==p){
					done=true;
					break;
				}
				total+=1;
				x++;
			}	
		}
	cout<<"Line = "<<x<<", column = "<<y<<".\n";
	}
}
