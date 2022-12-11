#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct constraint{
    int a,b,c;
};
int main(){
    int n,m;
    while(cin>>n>>m,n||m){
        int teens[n];
        R(i,0,n,1)
            teens[i]=i;
        if(m==0){
            int tmp=1;
            R(i,1,n+1,1)
                tmp*=i;
            cout<<tmp<<endl;
            continue;
        }
        else{
            constraint all[m];
            R(i,0,m,1){
                cin>> all[i].a >> all[i].b >> all[i].c;
            }
            int possi=0;
            do{
                bool valid=true;
                R(i,0,m,1){
                    int* posa= find(teens,teens+n,all[i].a);
                    int* posb= find(teens,teens+n,all[i].b);
                    int diff= abs(posa-posb);
                    if(all[i].c>0){
                        if(!(diff<=all[i].c)){
                            valid=false;
                            break;
                        }
                    }
                    else{
                        if(!(diff>= (-all[i].c))){
                            valid=false;
                            break;
                        }
                    }
                }
                if(valid)
                    possi++;
            }while(next_permutation(teens,teens+n));
            cout<<possi<<endl;
        }
    }
}
