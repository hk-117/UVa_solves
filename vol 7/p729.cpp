#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int dset;
    scanf("%d",&dset);
    while(dset--){
        int n,h;
        string hm;
        scanf("%d %d",&n,&h);
        R(i,0,n-h,1) hm+='0';
        R(i,0,h,1) hm+='1';
        do{
            printf("%s\n",hm.data());
        }while(next_permutation(hm.begin(),hm.end()));
        if(dset)
            putchar('\n');
    }
}
