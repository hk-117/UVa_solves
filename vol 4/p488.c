#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,f,i,j,k;
        scanf("%d %d",&a,&f);
        for(i=0;i<f;i++){
            if(i)
                printf("\n");
            for(j=1;j<=a;j++){
                for(k=1;k<=j;k++){
                    printf("%d",j);
                }
                printf("\n");
            }
            j--;
            for(j=j-1;j>=1;j--){
                for(k=1;k<=j;k++){
                    printf("%d",j);
                }
                printf("\n");
            }
        }
        if(t)
            printf("\n");
    }
}
