#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define max3(a,b,c) max(a,b)>max(b,c) ? max(a,b):max(b,c)
#define mx 100005
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 100000008
using namespace std;
int an[mx],cnt[mx],foc[mx],st[3*mx];
map<int,int> freq;
void build(int p,int L,int R){
    if(L==R){
        st[p]=cnt[L];
        return;
    }
    else{
        int mid=(L+R)/2;
        int left=2*p;
        int right=2*p+1;
        build(left,L,mid);
        build(right,mid+1,R);
        st[p]=max(st[left],st[right]);
    }
}
int rmaxq(int p,int L,int R,int i,int j){
    if(i>R || j<L)
        return -inf;
    if(L>=i && R<=j)
        return st[p];
    int mid=(L+R)/2;
    int left=2*p;
    int right=2*p+1;
    int p1=rmaxq(left,L,mid,i,j);
    int p2=rmaxq(right,mid+1,R,i,j);
    return max(p1,p2);
}
int main(){
    int n,q;
    while(scanf("%d",&n)==1 && n!=0){
        scanf("%d",&q);
        R(i,1,n+1,1){
            scanf("%d",&an[i]);
            freq[an[i]]++;
        }
        int previ=-inf,posi;
        R(i,1,n+1,1){
            int fi=freq[an[i]];
            cnt[i]=fi;
            if(an[i]!=previ){
                posi=i;
                previ=an[i];
            }
            foc[i]=posi;
        }
        build(1,1,n);
        int low,high,p[3];
        R(i,1,q+1,1){
            scanf("%d %d",&low,&high);
            if(an[low]!=an[high]){
                int similarlow= foc[low]+cnt[low];
                p[0]=similarlow-low;
                p[1]=high-foc[high]+1;
                p[2]=rmaxq(1,1,n,similarlow,foc[high]-1);
                printf("%d\n",max3(p[0],p[1],p[2]));
            }
            else{
                printf("%d\n",high-low+1);
            }
        }
        ms(an,0);
        ms(cnt,0);
        ms(foc,0);
        freq.clear();
    }
}
