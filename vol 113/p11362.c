#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char List[10005][15];
int N;
int cmp(const void *a,const void *b){
    const char *aa=(const char*) a;
    const char *bb=(const char*) b;
    int lena,lenb;
    lena=strlen(aa);
    lenb=strlen(bb);
    if(lena==lenb){
        return strcmp(aa,bb);
    }
    else{
        if(lena<lenb)
            return -1;
        else
            return 1;
    }
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        int consistent=1;
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%s",List[i]);
        }
        qsort(List,N,sizeof List[0],cmp);
        for(i=0;i<N && consistent;i++){
            for(j=i+1;j<N;j++){
                int k,same=1,l=strlen(List[i]);
                for(k=0;k<l;k++){
                    if(List[i][k]!=List[j][k]){
                        same=0;
                        break;
                    }
                }
                if(same){
                    consistent=0;
                    break;
                }
            }
        }
        if(consistent)
            puts("YES");
        else
            puts("NO");
    }
}
