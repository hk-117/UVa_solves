#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int T,tc=0;
    scanf("%d",&T);
    while(T--){
        tc++;
        int t1,t2,fnl,attend,total;
        int cts[3];
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&fnl,&attend,&cts[0],&cts[1],&cts[2]);
        sort(cts,cts+3);
        printf("Case %d: ",tc);
        total=t1+t2+fnl+attend+(cts[1]+cts[2])/2;
        if(total>=90){
            printf("A\n");
        }
        else if(total>=80 && total<90){
            printf("B\n");
        }
        else if(total>=70 && total<80){
            printf("C\n");
        }
        else if(total>=60 && total<70){
            printf("D\n");
        }
        else{
            printf("F\n");
        }
    }
}
