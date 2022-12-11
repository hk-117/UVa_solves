#include<stdio.h>
void swap(int *a,int *b){
    int tmp= *a;
    *a=*b;
    *b=tmp;
}
int main(){
    int N,L,Train[55];
    scanf("%d",&N);
    while(N--){
        int i,j,swp=0,spd;
        scanf("%d",&L);
        for(i=0;i<L;i++){
            scanf("%d",&Train[i]);
        }
        for(i=0;i<L;i++){
            spd=0;
            for(j=0;j<L-1;j++){
                if(Train[j]>Train[j+1]){
                    spd=1;
                    swap(&Train[j],&Train[j+1]);
                    swp++;
                }
            }
            if(!swp)
                break;
        }
        printf("Optimal train swapping takes %d swaps.\n",swp);
    }
}
