#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void war(vector< vector<int> > &lands,int n,int r,int c){
    vector< vector<int> > before_war(lands);
    R(i,0,r,1){
        R(j,0,c,1){
            int attack=(before_war[i][j]+1)%n;
            if(i==0){
                if(j==0){
                    if(c>1 && before_war[i][j+1]==attack)
                        lands[i][j+1]=before_war[i][j];
                    if(r>1 && before_war[i+1][j]==attack)
                        lands[i+1][j]=before_war[i][j];
                }
                else if(j== c-1){
                    if(before_war[i][j-1]==attack)
                        lands[i][j-1]=before_war[i][j];
                    if(r>1 && before_war[i+1][j]==attack)
                        lands[i+1][j]=before_war[i][j];
                }
                else{
                    if(before_war[i][j+1]==attack)
                        lands[i][j+1]=before_war[i][j];
                    if(r>1 && before_war[i+1][j]==attack)
                        lands[i+1][j]=before_war[i][j];
                    if(before_war[i][j-1]==attack)
                        lands[i][j-1]=before_war[i][j];
                }
            }
            else if(i==r-1){
                 if(j==0){
                    if(before_war[i-1][j]==attack)
                        lands[i-1][j]=before_war[i][j];
                    if(c>1 && before_war[i][j+1]==attack)
                        lands[i][j+1]=before_war[i][j];
                }
                else if(j== c-1){
                    if(before_war[i-1][j]==attack)
                        lands[i-1][j]=before_war[i][j];
                    if(before_war[i][j-1]==attack)
                        lands[i][j-1]=before_war[i][j];
                }
                else{
                    if(before_war[i][j+1]==attack)
                        lands[i][j+1]=before_war[i][j];
                    if(before_war[i-1][j]==attack)
                        lands[i-1][j]=before_war[i][j];
                    if(before_war[i][j-1]==attack)
                        lands[i][j-1]=before_war[i][j];
                }
            }
            else{
                if(j==0){
                    if(before_war[i-1][j]==attack)
                        lands[i-1][j]=before_war[i][j];
                    if(before_war[i][j+1]==attack)
                        lands[i][j+1]=before_war[i][j];
                    if(before_war[i+1][j]==attack)
                        lands[i+1][j]=before_war[i][j];
                }
                else if(j==c-1){
                    if(before_war[i-1][j]==attack)
                        lands[i-1][j]=before_war[i][j];
                    if(before_war[i][j-1]==attack)
                        lands[i][j-1]=before_war[i][j];
                    if(before_war[i+1][j]==attack)
                        lands[i+1][j]=before_war[i][j];
                }
                else{
                    if(before_war[i-1][j]==attack)
                        lands[i-1][j]=before_war[i][j];
                    if(before_war[i][j+1]==attack)
                        lands[i][j+1]=before_war[i][j];
                    if(before_war[i+1][j]==attack)
                        lands[i+1][j]=before_war[i][j];
                    if(before_war[i][j-1]==attack)
                        lands[i][j-1]=before_war[i][j];
                }
            }
        }
    }
}
int main(){
    int n,r,c,k;
    while(cin>>n>>r>>c>>k, n && r && c && k){
        vector<vector<int>> lands(r,vector<int>(c));
        R(i,0,r,1){
            R(j,0,c,1){
                cin>>lands[i][j];
            }
        }
        R(i,1,k+1,1){
            war(lands,n,r,c);
        }
        R(i,0,r,1){
            R(j,0,c,1){
                cout<<lands[i][j];
                if(j!=c-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
}
