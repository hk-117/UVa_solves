#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct data{
    char name[25];
    int low,high;
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int dbsize;
        scanf("%d",&dbsize);
        data database[dbsize];
        char nm[25];
        int l,h;
        R(i,0,dbsize,1){
            scanf("%s %d %d",nm,&l,&h);
            strcpy(database[i].name,nm);
            database[i].low=l;
            database[i].high=h;
        }
        int q;
        scanf("%d",&q);
        R(i,0,q,1){
            int pr,trk=0;
            strcpy(nm,"UNDETERMINED");
            scanf("%d",&pr);
            R(j,0,dbsize,1){
                if(database[j].low<=pr && database[j].high>=pr){
                    trk++;
                    if(trk>1){
                        strcpy(nm,"UNDETERMINED");
                        break;
                    }
                    strcpy(nm,database[j].name);
                }
            }
            puts(nm);
        }
        if(t)
            puts("");
    }
}
