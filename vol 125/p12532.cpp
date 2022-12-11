#include<bits/stdc++.h>
#define mx 1000005
using namespace std;
int A[mx],st[3*mx];
void build(int p,int L,int R){
    if(L==R)
        st[p]=A[L];
    else{
        int mid= (L+R)/2;
        int left= 2*p;
        int right= 2*p+1;
        build(left,L,mid);
        build(right,mid+1,R);
        int p1=st[left],p2=st[right];
        st[p]= p1*p2;
    }
}
int RPQ(int p,int L,int R,int i,int j){
    if(i>R || j<L)
        return 1;
    if(L>=i && R<=j)
        return st[p];
    int mid= (L+R)/2;
    int left= 2*p;
    int right= 2*p+1;
    int p1=RPQ(left,L,mid,i,j);
    int p2=RPQ(right,mid+1,R,i,j);
    return p1*p2;
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
        st[p]=st[left]*st[right];
    }
}

int main(){
	int res,n,k;
    while(cin>>n>>k){
        int x,y,i,inp;
        char Dir;
        for(i=0;i<n;i++){
            cin>>inp;
            if(inp>0){
                A[i]=1;
            }
            else if(inp<0){
                A[i]=-1;
            }
            else{
                A[i]=0;
            }
        }
        build(1,0,n-1);
        while(k--){
            cin>>Dir>>x>>y;
            if(Dir=='P'){
                res= RPQ(1,0,n-1,x-1,y-1);
                if(res>0)
                    putchar('+');
                else if(res<0)
                    putchar('-');
                else
                    putchar('0');
            }
            else{
                if(y>0){
                    y=1;
                }
                else if(y<0){
                    y=-1;
                }
                else{
                    y=0;
                }
                update(1,0,n-1,x-1,y);
            }
        }
        putchar('\n');
    }
}
