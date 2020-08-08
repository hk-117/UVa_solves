#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        map<string,bool> Dc;
        vector<string> D;
        string inp;
        while(cin>>inp,inp!="#"){
            Dc[inp]=true;
            D.push_back(inp);
        }
        while(cin>>inp,inp!="#"){
            if(Dc.find(inp) != Dc.end()){
                cout<<inp<<" is correct"<<endl;
            }
            else{
                int wLen= inp.size();
                int vlen= D.size();
                cout<< inp <<":";
                R(i,0,vlen,1){
                    int tmplen= D[i].size();
                    if(tmplen==wLen){
                        int diff=0;
                        R(j,0,tmplen,1){
                            if(D[i][j] != inp[j])
                                diff++;
                        }
                        if(diff==1)
                            cout<<" "<<D[i];
                    }
                    else if(tmplen+1 == wLen){
                        R(j,0,wLen,1){
                            string tmp= inp;
                            tmp.replace(j,1,"");
                            if(tmp==D[i]){
                                cout<<" "<<D[i];
                                break;
                            }
                        }
                    }
                    else if(tmplen-1==wLen){
                        R(j,0,tmplen,1){
                            string tmp= D[i];
                            tmp.replace(j,1,"");
                            if(tmp==inp){
                                cout<<" "<<D[i];
                                break;
                            }
                        }
                    }
                    else{
                        //pass
                    }
                }
                cout<<endl;
            }
        }
        cin.ignore();
        if(n)
            cout<<endl;
    }
}
