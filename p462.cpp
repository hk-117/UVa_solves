#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
char suits[]="SHDC";
struct suitDetails{
    bool king=0,queen=0,jack=0,ace=0;
    int totalCards=0;
    bool isStopped(){
        if(ace){
            return true;
        }
        else if(king && totalCards>=2){
            return true;
        }
        else if(queen && totalCards>=3){
            return true;
        }
        else{
            return false;
        }
    }
    int subtractNum(){
        int tot=0;
        if(king && totalCards==1)
            tot+=1;
        if(queen && totalCards<=2)
            tot+=1;
        if(jack && totalCards<=3)
            tot+=1;
        return tot;
    }
    int addNum(){
        int pts=0;
        if(totalCards==2)
            pts=1;
        if(totalCards==1)
            pts=2;
        if(totalCards==0)
            pts=2;
        return pts;
    }
};
struct handDetails{
    int totalPoints=0;
    suitDetails allSuits[4];
    bool isAllStopped(){
        R(i,0,4,1){
            if(!allSuits[i].isStopped()){
                return false;
            }
        }
        return true;
    }
    int ptWithRules(){
        int ptWithRule=totalPoints;
        R(i,0,4,1){
            ptWithRule+=allSuits[i].addNum() - allSuits[i].subtractNum();
        }
        return ptWithRule;
    }
    int ptWithoutRules(){
        int ptWithoutRule=totalPoints;
        R(i,0,4,1){
            ptWithoutRule= ptWithoutRule - allSuits[i].subtractNum();
        }
        return ptWithoutRule;
    }
    char maxNumCards(){
        int mx=allSuits[0].totalCards;
        char mName=suits[0];
        R(i,1,4,1){
            if(allSuits[i].totalCards > mx){
                mx=allSuits[i].totalCards;
                mName=suits[i];
            }
        }
        return mName;
    }
};
int suitNumCheck(char card){
    int pos;
    if(card=='S')
        pos=0;
    else if(card=='H')
        pos=1;
    else if(card=='D')
        pos=2;
    else if(card=='C')
        pos=3;
    return pos;
}
int main(){
    string inp;
    while(getline(cin,inp)){
        stringstream ss(inp);
        handDetails Hand;
        string card;
        while(ss>>card){
            char vl= card[0],st= card[1];
            int suitNum= suitNumCheck(st);
            if(vl=='A'){
                Hand.totalPoints+=4;
                Hand.allSuits[suitNum].ace=true;
                Hand.allSuits[suitNum].totalCards++;
            }
            else if(vl=='K'){
                Hand.totalPoints+=3;
                Hand.allSuits[suitNum].king=true;
                Hand.allSuits[suitNum].totalCards++;
            }
            else if(vl=='Q'){
                Hand.totalPoints+=2;
                Hand.allSuits[suitNum].queen=true;
                Hand.allSuits[suitNum].totalCards++;
            }
            else if(vl=='J'){
                Hand.totalPoints+=1;
                Hand.allSuits[suitNum].jack=true;
                Hand.allSuits[suitNum].totalCards++;
            }
            else{
                Hand.allSuits[suitNum].totalCards++;
            }
        }
        int ptWithRule= Hand.ptWithRules();
        int ptWithoutRule= Hand.ptWithoutRules();
        bool Stopped= Hand.isAllStopped();
        if(ptWithRule< 14){
            puts("PASS");
        }
        else if(ptWithoutRule >=16 && Stopped){
            puts("BID NO-TRUMP");
        }
        else if(ptWithRule >= 14){
            printf("BID %c\n",Hand.maxNumCards());
        }
    }
}
