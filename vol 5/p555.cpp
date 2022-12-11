#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
char values[]="23456789TJQKA";
char suits[]="CDSH";
char dealerName[]="SWNE";
int rankCard(char value,char suit){
    R(i,0,13,1){
        if(values[i]==value){
            R(j,0,4,1){
                if(suits[j]==suit){
                    return (j*13+i);
                }
            }
        }
    }
}
char suit(int card){
    if(card>=0 && card<=12)
        return suits[0];
    else if(card>=13 && card <=25)
        return suits[1];
    else if(card>=26 && card<=38)
        return suits[2];
    else
        return suits[3];
}
char value(int card){
    return values[card%13];
}
int main(){
    char dealer;
    map<char,int> dNum;
    dNum['S']=0,dNum['W']=1,dNum['N']=2,dNum['E']=3;
    while(cin>>dealer,dealer!='#'){
        string inp,dm;
        cin>>inp>>dm;
        inp+=dm;
        set<int>player[4];
        int startPoint=dNum[dealer]+1;
        R(i,0,inp.size(),2){
            char st=inp[i];
            char vl=inp[i+1];
            player[startPoint%4].insert(rankCard(vl,st));
            startPoint++;
        }
        R(i,0,4,1){
            printf("%c:",dealerName[i]);
            for(auto it=player[i].begin();it!=player[i].end();it++){
                printf(" %c%c",suit(*it),value(*it));
            }
            putchar('\n');
        }
    }
}
