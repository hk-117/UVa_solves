#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define ms(a,b) memset(a,b,sizeof(a))
#define mx 1000005
using namespace std;
int resistors[mx],st[3*mx];
void build(int p,int L,int R){
    if(L==R)
        st[p]=resistors[L];
    else{
        int mid= (L+R)/2;
        int left= 2*p;
        int right= 2*p+1;
        build(left,L,mid);
        build(right,mid+1,R);
        int p1=st[left],p2=st[right];
        st[p]= p1+p2;
    }
}
int RSQ(int p,int L,int R,int i,int j){
    if(i>R || j<L)
        return 0;
    if(L>=i && R<=j)
        return st[p];
    int mid= (L+R)/2;
    int left= 2*p;
    int right= 2*p+1;
    int p1=RSQ(left,L,mid,i,j);
    int p2=RSQ(right,mid+1,R,i,j);
    return p1+p2;
}
void update(int p,int L,int R,int pos,int new_val){
    if(L==R){
        st[p]=new_val;
    }
    else{
        int mid=(L+R)/2;
        int left= 2*p;
        int right= 2*p+1;
        if(pos<=mid)
            update(left,L,mid,pos,new_val);
        else
            update(right,mid+1,R,pos,new_val);
        st[p]=st[left]+st[right];
    }
}

int main(){
    int n,tc=0;
    while(scanf("%d",&n)==1 && n!=0){
        ++tc;
        R(i,1,n+1,1){
            scanf("%d",&resistors[i]);
        }
        build(1,1,n);
        string operations;
        getchar();
        printf("Case %d:\n",tc);
        while(getline(cin,operations),operations!="END"){
            char com;
            int a,b;
            sscanf(operations.c_str(),"%c %d %d",&com,&a,&b);
            if(com=='S'){
                update(1,1,n,a,b);
            }
            else{
                printf("%d\n",RSQ(1,1,n,a,b));
            }
        }
        if(tc==1)
            puts("");
        ms(resistors,0);
    }
}
