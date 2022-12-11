#include<bits/stdc++.h>
using namespace std;
int main(){
	int st,a,b,c;
	int res;
	while(scanf("%d %d %d %d",&st,&a,&b,&c), (st||a||b||c)){
	int fround,sround,tround;	
	if(st<a){
        	fround = 40 + st - a;
   	 }else{
        	fround = st-a;
    	}
 
    	if(b<a){
        	sround = 40 + b - a;
   	 }else{
        	sround = b - a;
   	 }
 
   	 if(b<c){
        	tround = 40 + b - c;
   	 }else{
        	tround = b - c;
   	 }
		res=1080+9*(fround+sround+tround);
		cout<<res<<"\n";
	}
	return 0;
}
