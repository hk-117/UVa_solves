#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c,n,tc=0;
    while(scanf("%d%d%d",&r,&c,&n),r||n||c){
        bitset<10000> rows,cols;
        int bposcl,bposrw;
        for(int i=0;i<=n;i++){
            int a,b;
            if(i==n){
                scanf("%d%d",&bposrw,&bposcl);
            }
            else{
                scanf("%d%d",&a,&b);
                rows.set(a);
                cols.set(b);
            }
        }
        int rowmoves[]={1,-1,0,0,0};
        int colmoves[]={0,0,1,-1,0};
        bool possible=false;
        for(int i=0;i<5;i++){
            int posc=bposcl+colmoves[i];
            int posr=bposrw+rowmoves[i];
            if(posc<0 || posc>c-1 || posr<0 || posr>r-1){
                continue;
            }
            else if(!(cols[posc] || rows[posr])){
                possible=true;
                break;
            }
        }
        if(possible){
            printf("Case %d: Escaped again! More 2D grid problems!\n",++tc);
        }
        else{
            printf("Case %d: Party time! Let's find a restaurant!\n",++tc);
        }
    }
}
