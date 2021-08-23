#include<stdio.h>
#include<math.h>
int Val[530000];
void PowerTwo(){
    int i,j;
    Val[1]=1;
    Val[2]=2;
    for(i=2;i<=19;i++){
        int pw=pow(2,i);
        j=pw;
        while(pw){
            Val[j]=pw;
            pw-=2;
            j--;
        }
    }
}
int main(){
    int N;
    PowerTwo();
    while(scanf("%d",&N)==1 && N){
        printf("%d\n",Val[N]);
    }
}
