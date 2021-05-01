#include<bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    while(cin>>inp,inp!="0"){
        printf("Original number was %s\n",inp.data());
        map<int,bool> Tbl;
        string a=inp,b=inp,c;
        int res,cnt=1,anum,bnum;
        sort(b.begin(),b.end());
        sort(a.begin(),a.end(),greater<char>());
        anum=atoi(a.c_str());
        bnum=atoi(b.c_str());
        res=anum-bnum;
        printf("%d - %d = %d\n",anum,bnum,res);
        c=to_string(res);
        Tbl[res]=true;
        while(true){
            a=c;
            b=c;
            sort(b.begin(),b.end());
            sort(a.begin(),a.end(),greater<char>());
            anum=atoi(a.c_str());
            bnum=atoi(b.c_str());
            res=anum-bnum;
            printf("%d - %d = %d\n",anum,bnum,res);
            cnt++;
            if(Tbl[res]){
                printf("Chain length %d\n\n",cnt);
                break;
            }
            c=to_string(res);
            Tbl[res]=true;
        }
    }
}
