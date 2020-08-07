#include<bits/stdc++.h>
using namespace std;
struct cars{
    int times=0;
    char name[25],smlName[25];
};
int cmpfn(const void *a,const void *b){
    struct cars *aa,*bb;
    aa=(struct cars*) a;
    bb=(struct cars*) b;
    if(!((aa->times)-(bb->times))){
        return strcmp(aa->smlName,bb->smlName);
    }
    else
        return (aa->times)-(bb->times);
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        char line[250];
        int i,pos=0,m,s,ms,nw=n,len,rem,rw;
        struct cars D[150];
        getchar();
        while(nw--){
            fgets(line,sizeof(line),stdin);
            line[strcspn(line,"\r\n")]='\0';
            sscanf(line,"%s : %d min %d sec %d ms",D[pos].name,&m,&s,&ms);
            len=strlen(D[pos].name);
            for(i=0;i<len;i++){
                D[pos].smlName[i]=tolower(D[pos].name[i]);
            }
            D[pos].smlName[i]='\0';
            D[pos].times+= m*60*1000 + s*1000+ms;
            pos++;
        }
        getchar();
        qsort(D,n,sizeof(D[0]),cmpfn);
        rw= n/2;
        rem= n%2;
        for(i=0;i<rw;i++){
            printf("Row %d\n",i+1);
            printf("%s\n%s\n",D[2*i].name,D[2*i+1].name);
        }
        if(rem){
            printf("Row %d\n",i+1);
            printf("%s\n",D[2*i].name);
        }
        putchar('\n');
    }
}
