#include<stdio.h>
#include<math.h>
int main(){
    int N;
    while(scanf("%d",&N)==1 && N){
        printf("%d\n",(int) (log(N)/log(2)));
    }
}
