#include<bits/stdc++.h>
#define mx 1000
using namespace std;
int Mat[30][30];
string line;
int main(){
    int t,n;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        int i,j,k,l,maxSub,subRect;
        n=0;
        while(getline(cin,line),line.size()){
            for(i=0;i<line.size();i++){
                if(line[i] !='0')
                    Mat[n][i]=1;
                else
                    Mat[n][i]= -mx;
                if(n>0) Mat[n][i] += Mat[n-1][i];
                if(i>0) Mat[n][i] += Mat[n][i-1];
                if(i>0 && n >0) Mat[n][i] -= Mat[n-1][i-1];
            }
            n++;
        }
        maxSub= -mx;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=i;k<n;k++){
                    for(l=j;l<n;l++){
                        subRect= Mat[k][l];
                        if(i>0) subRect -= Mat[i-1][l];
                        if(j>0) subRect -= Mat[k][j-1];
                        if(i>0 && j>0) subRect += Mat[i-1][j-1];
                        maxSub= max(maxSub,subRect);
                    }
                }
            }
        }
        if(maxSub <0)
            puts("0");
        else
            printf("%d\n",maxSub);
        if(t)
            puts("");
    }
}
