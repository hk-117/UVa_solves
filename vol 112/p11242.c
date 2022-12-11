#include<stdio.h>
#include<stdlib.h>
double R[250];
int cmp(const void* a, const void* b){
    double *aa,*bb;
    aa = (double*)a;
    bb = (double*)b;
    if(*aa-*bb <0.0)
        return -1;
    else if(*aa-*bb>0.0)
        return 1;
    else
        return 0;
}
int main(){
    int f,r,Fs[15],Rs[15];
    while(scanf("%d",&f)==1 && f){
        int i,j,k=0;
        double mx=-1.0;
        scanf("%d",&r);
        for(i=0;i<f;i++){
            scanf("%d",&Fs[i]);
        }
        for(i=0;i<r;i++){
            scanf("%d",&Rs[i]);
        }
        for(i=0;i<f;i++){
            for(j=0;j<r;j++){
                R[k++]= (double)Rs[j]/(double)Fs[i];
            }
        }
        qsort(R,k,sizeof(double),cmp);
        for(i=0;i<k-1;i++){
            if(mx < R[i+1]/R[i])
                mx = R[i+1]/R[i];
        }
        printf("%.2lf\n",mx);
    }
}
