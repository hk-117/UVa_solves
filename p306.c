#include<stdio.h>
#include<string.h>
#define mx 10005
char msg[250];
int p[mx],rank[mx],setSize[mx],poses[mx];
int numSets;
void UnionFind(int N){
    int i;
    numSets=N;
    for(i=0;i<N;i++){
        setSize[i]=1;
    }
    for(i=0;i<N;i++){
        p[i]=i;
    }
}
int findSet(int i){
    return (p[i]==i)? i: (p[i]=findSet(p[i]));
}
int isSameSet(int i,int j){
    return findSet(i)==findSet(j);
}
void unionSet(int i,int j){
    if(!isSameSet(i,j)){
        int x=findSet(i),y=findSet(j);
        numSets--;
        if(rank[x]>rank[y]){
            p[y]=x;
            setSize[x]+=setSize[y];
        }
        else{
            p[x]=y;
            setSize[y]+=setSize[x];
            if(rank[x]==rank[y])
                rank[y]++;
        }
    }
}
int sizeOfSet(int i){
    return setSize[findSet(i)];
}
int findChar(int pi,int j){
    int i;
    for(i=1;i<=pi;i++){
        j= poses[j];
    }
    return j;
}
int main(){
    int n;
    while(scanf("%d",&n) && n){
        int i,k;
        memset(poses,-1,n*sizeof(int));
        memset(rank,0,n*sizeof(int));
        UnionFind(n);
        for(i=0;i<n;i++){
            scanf("%d",&poses[i]);
            poses[i]--;
            unionSet(i,poses[i]);
        }
        while(scanf("%d",&k) && k){
            int len,j;
            char result[250];
            getchar();
            fgets(msg,sizeof(msg),stdin);
            msg[strcspn(msg,"\r\n")]='\0';
            len=strlen(msg);
            for(j=len;j<n;j++)
                msg[j]=' ';
            msg[j]='\0';
            for(j=0;j<n;j++){
                int pi,c;
                c=sizeOfSet(j);
                pi= k%c;
                result[findChar(pi,j)]=msg[j];
            }
            result[j]='\0';
            puts(result);
        }
        putchar('\n');
    }
}
