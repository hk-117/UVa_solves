#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>D;
    map<string,bool> Dc;
    string inp;
    R(i,0,n,1){
        cin>>inp;
        D.push_back(inp);
        Dc[inp]=true;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>inp;
        if(Dc.find(inp) != Dc.end()){
            cout<<inp<<" is correct"<<endl;
        }
        else{
            bool found=false;
            int wLen= inp.size();
            int vlen= D.size();
            R(i,0,vlen,1){
                if(found)
                    break;
                int tmplen= D[i].size();
                if(tmplen==wLen){
                    int diff=0;
                    int swappos;
                    R(j,0,tmplen,1){
                        if(D[i][j] != inp[j]){
                            diff++;
                            if(diff==1){
                                swappos=j;
                            }
                        }
                    }
                    if(diff==1){
                        cout<<inp<<" is a misspelling of "<<D[i]<<endl;
                        found=true;
                    }
                    else if(!found){
                        string st=inp;
                        if(swappos<tmplen && tmplen>1){
                            swap(st[swappos],st[swappos+1]);
                        }
                        if(st==D[i]){
                            cout<< inp <<" is a misspelling of "<<D[i]<<endl;
                            found=true;
                        }
                    }
                }
                else if(tmplen+1 == wLen){
                    R(j,0,wLen,1){
                        string tmp= inp;
                        tmp.replace(j,1,"");
                        if(tmp==D[i]){
                            found=true;
                            cout<<inp<<" is a misspelling of " <<D[i]<<endl;
                            break;
                        }
                    }
                }
                else if(tmplen-1==wLen){
                    R(j,0,tmplen,1){
                        string tmp= D[i];
                        tmp.replace(j,1,"");
                        if(tmp==inp){
                            found=true;
                            cout<<inp<<" is a misspelling of "<<D[i]<<endl;
                            break;
                        }
                    }
                }
                else{
                    //pass
                }
            }
            if(!found){
                cout<<inp<<" is unknown"<<endl;
            }
        }
    }
}
