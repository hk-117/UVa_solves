#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define pb push_back
using namespace std;

int main(){
    int row,col;
    while(cin>>row>>col){
        vector<pair<vector<int>,vector<int>>> adjL(col);
        R(i,0,row,1){
            int poses;
            cin>>poses;
            vector<int> rowposes(poses);
            R(j,0,poses,1){
                cin>>rowposes[j];
            }
            int data;
            R(j,0,poses,1){
                cin>>data;
                adjL[rowposes[j]-1].first.pb(data);
                adjL[rowposes[j]-1].second.pb(i+1);
            }
        }
        cout<< col <<" "<< row <<endl;
        R(i,0,col,1){
            cout<< adjL[i].second.size();
            if(!adjL[i].second.size()){
                cout<<"\n"<<endl;
            }
            else{
                R(j,0,adjL[i].second.size(),1)
                    cout<<" "<<adjL[i].second[j];
                cout<<endl;
                R(j,0,adjL[i].first.size(),1){
                    if(j)
                        cout<<" ";
                    cout<< adjL[i].first[j];
                }
                cout<<endl;
            }
        }
    }
}
