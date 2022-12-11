#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    string colors="BGC";
    string line;
    while(getline(cin,line)){
        map<string,int> moves;
        map<char,int> poses;
        poses['B']=0,poses['G']=1,poses['C']=2;
        int bottles[3][3];
        stringstream ss(line);
        R(i,0,3,1){
            R(j,0,3,1){
                ss>>bottles[i][j];
            }
        }
        int mn=INT_MAX;
        R(j,0,6,1){
            int mv=0;
            R(i,0,3,1){
                if(i==poses[colors[0]])
                    continue;
                mv+= bottles[0][i];
            }
            R(i,0,3,1){
                if(i==poses[colors[1]])
                    continue;
                mv+= bottles[1][i];
            }
            R(i,0,3,1){
                if(i==poses[colors[2]])
                    continue;
                mv+= bottles[2][i];
            }
            mn= (mn<mv) ? mn:mv;
            moves[colors]=mv;
            next_permutation(colors.begin(),colors.end());
        }
        for(auto it=moves.begin();it!=moves.end();it++){
            if(it->second == mn){
                cout<< it->first <<" "<< mn <<endl;
                break;
            }
        }
    }
}
