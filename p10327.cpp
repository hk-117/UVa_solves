#include<cstdio>
using namespace std;
int main(){
    int N,nums[1010];
    while(scanf("%d",&N)==1){
        int i,j,sw=0,spd,tmp;
        for(i=0;i<N;i++){
            scanf("%d",&nums[i]);
        }
        for(i=0;i<N;i++){
            spd=0;
            for(j=0;j<N-i-1;j++){
                if(nums[j]>nums[j+1]){
                    spd=1;
                    sw++;
                    tmp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=tmp;
                }
            }
            if(!spd)
                break;
        }
        printf("Minimum exchange operations : %d\n",sw);
    }
}
