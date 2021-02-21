#include<cstdio>
using namespace std;
long long sw;
void merge(int *arr,int beg,int mid,int end){
    int i=beg,j=mid+1,index=0,tmp[end-beg+1],k;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            tmp[index++]=arr[i++];
        }
        else{
            sw+= (j-beg-index);
            tmp[index++]=arr[j++];
        }
    }
    if(i>mid){
        while(j<=end){
            tmp[index++]=arr[j++];
        }
    }
    else{
        while(i<=mid){
            tmp[index++]=arr[i++];
        }
    }
    for(k=0;k<index;k++){
        arr[beg+k]=tmp[k];
    }
}
void mergeSort(int *arr,int beg,int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
int main(){
    int N,arr[500005];
    while(scanf("%d",&N)==1 && N){
        int i;
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        sw=0;
        mergeSort(arr,0,N-1);
        printf("%lld\n",sw);
    }
}
