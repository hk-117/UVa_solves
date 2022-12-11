#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int heights[100001];
int main(){
    int l,h,r,rmx=0;
    while(scanf("%d",&l)==1 && l!=0){
        scanf("%d %d",&h,&r);
        R(i,l,r,1){
            if(heights[i]<h){
                heights[i]=h;
            }
        }
        rmx=(rmx>r)?rmx:r;
    }
    int st=0,pos=0;
    R(i,0,rmx+1,1){
        if(heights[i] != st){
            if(pos==0){
                printf("%d %d",i,heights[i]);
                pos++;
            }
            else{
                printf(" %d %d",i,heights[i]);
            }
            st=heights[i];
        }
    }
    puts("");
}
