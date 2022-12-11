#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define RR(i,a,b,c) for(int i=a;i>b;i-=c)
using namespace std;
bool chkclap(int &clap,int &beg,int k,int m,int i){
    if(beg%7==0){
        if(m==i)
            clap++;
        if(clap==k && m==i){
            return true;
        }
    }
    else{
        string st= to_string(beg);
        if(st.find('7') != -1){
            if(m==i)
                clap++;
            if(clap==k && m==i){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m,k;
    while(cin>>n>>m>>k,n||m||k){
        int clap=0,beg=0,lastn=0;
        bool flg=false;
        while(true){
            R(i,lastn+1,n+1,1){
                beg++;
                flg= chkclap(clap,beg,k,m,i);
                if(flg){
                    cout<<beg<<endl;
                    break;
                }
            }
            if(flg) break;
            lastn=n;
            RR(i,lastn-1,0,1){
                beg++;
                flg=chkclap(clap,beg,k,m,i);
                if(flg){
                    cout<<beg<<endl;
                    break;
                }
            }
            if(flg) break;
            lastn=1;
        }
    }
}
