#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
struct Population{
    int i,j,count;
};
int killed[1030][1030];
int main(){
    int scene,d,n;
    scanf("%d",&scene);
    while(scene--){
        scanf("%d",&d);
        scanf("%d",&n);
        Population res,pop[n];
        res.i = -1;
        res.j = -1;
        res.count = 0;
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&pop[i].i,&pop[i].j,&pop[i].count);
        }
        for(int k=0;k<n;k++){
            for(int i=pop[k].i-d;i<=pop[k].i+d;i++){
                for(int j=pop[k].j-d;j<=pop[k].j+d;j++){
                    if(i>=0 && i<1025 && j>=0 && j<1025){
                        killed[i][j] += pop[k].count;
                    }
                }
            }
        }
        for(int i=0;i<1025;i++){
            for(int j=0;j<1025;j++){
                if(killed[i][j]>res.count){
                    res.i = i;
                    res.j = j;
                    res.count = killed[i][j];
                }
                killed[i][j]=0;
            }
        }
        printf("%d %d %d\n",res.i,res.j,res.count);
    }
}
