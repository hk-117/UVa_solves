#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Vector Vector;
typedef struct Node Node;
struct Node{
    int data;
    Node* next;
};
struct Vector{
    Node* head;
    Node* tail;
};
int n,m,l,visited[10005];
Vector *G[10005];
void initGraph(int n){
    int i;
    for(i=1;i<=n;i++){
        Vector *tmp = malloc(sizeof (Vector));
        tmp->head=NULL;
        tmp->tail=NULL;
        G[i]=tmp;
    }
}
void inBack(int gi,int data){
    int i;
    Node *nw= malloc(sizeof(Node));
    nw->data= data;
    nw->next=NULL;
    if(G[gi]->head == NULL){
        G[gi]->head= nw;
        G[gi]->tail= nw;
    }
    else{
        G[gi]->tail->next = nw;
        G[gi]->tail= nw;
    }
}
void dfs(int u){
    int i;
    Node *v=G[u]->head;
    visited[u]=1;
    while(v!=NULL){
        if(visited[v->data]==-1){
            dfs(v->data);
        }
        v=v->next;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i,j,gi,data,res=0;
        scanf("%d %d %d",&n,&m,&l);
        initGraph(n);
        memset(visited,-1,(n+1)*sizeof(int));
        for(i=1;i<=m;i++){
            scanf("%d %d",&gi,&data);
            inBack(gi,data);
        }
        for(i=1;i<=l;i++){
            scanf("%d",&data);
            dfs(data);
        }
        for(i=1;i<=n;i++){
            if(visited[i]!= -1)
                res++;
        }
        printf("%d\n",res);
    }
}
