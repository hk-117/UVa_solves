#include<bits/stdc++.h>
using namespace std;
typedef struct{
    bool isPair,isTwoPair,isThree,isFour,isFullHouse,isFlash,isStraight,isStraightFlash;
    int PairRank,TwoPairRank,ThreeRank,FourRank,OneRank;
} Holder;

Holder Black,White;

int getRank(char c){
    if(c=='T')
        return 10;
    else if(c=='J')
        return 11;
    else if(c=='Q')
        return 12;
    else if(c=='K')
        return 13;
    else if(c=='A')
        return 14;
    else 
        return c-'0';
}
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second>b.second;
    else
        return a.first>b.first;
}
bool cmpfn(string a,string b){
    int i=getRank(a[0]),j=getRank(b[0]);
    return i<j;
}
bool checkFlash(vector<string> Cards){
    for(int i=0;i<4;i++){
        if(Cards[i][1]!=Cards[i+1][1])
            return false;
    }
    return true;
}
bool checkStraight(vector<string> Cards){
    for(int i=0;i<4;i++){
        if(getRank(Cards[i][0])+1 != getRank(Cards[i+1][0]))
            return 0;
    }
    return 1;
}
int main(){
    string line;
    while(getline(cin,line)){
        stringstream ss(line);
        vector<string> H1,H2;
        int cnt=0,winner;
        string st;
        map<int,int> B,W;
        vector<pair<int,int>> Bc,Wc;
        while(ss>>st){
            cnt++;
            if(cnt>5){
                H2.push_back(st);
                W[st[0]]++;
            }
            else{
                H1.push_back(st);
                B[st[0]]++;
            }
        }
        for(auto it=B.begin();it!=B.end();it++)
            Bc.push_back(make_pair(it->second,getRank(it->first)));
        for(auto it=W.begin();it!=W.end();it++)
            Wc.push_back(make_pair(it->second,getRank(it->first)));
        sort(H1.begin(),H1.end(),cmpfn);
        sort(H2.begin(),H2.end(),cmpfn);
        sort(Bc.begin(),Bc.end(),cmp);
        sort(Wc.begin(),Wc.end(),cmp);
        Black.isPair=false;
        Black.isTwoPair=false;
        Black.isThree=false;
        Black.isFour=false;
        Black.isFullHouse=false;
        Black.isFlash=checkFlash(H1);
        Black.isStraight=checkStraight(H1);
        if(Black.isStraight && Black.isFlash)
            Black.isStraightFlash=true;
        else
            Black.isStraightFlash=false;
        White.isPair=false;
        White.isTwoPair=false;
        White.isThree=false;
        White.isFour=false;
        White.isFullHouse=false;
        White.isFlash=checkFlash(H2);
        White.isStraight=checkStraight(H2);
        if(White.isStraight && White.isFlash)
            White.isStraightFlash=true;
        else
            White.isStraightFlash=false;
        for(auto it=Bc.begin();it!=Bc.end();it++){
            if(it->first == 4){
                Black.isFour=true;
                Black.FourRank=it->second;
            }
            else if(it->first==3){
                Black.isThree=true;
                Black.ThreeRank=it->second;
                if(Black.isPair)
                    Black.isFullHouse=true;
            }
            else if(it->first==2){
                if(Black.isThree){
                    Black.isFullHouse=true;
                }
                else if(Black.isPair){
                    Black.isTwoPair=true;
                    Black.TwoPairRank=it->second;
                }
                else{
                    Black.isPair=true;
                    Black.PairRank=it->second;
                }
            }
            else{
                if(Black.isTwoPair)
                    Black.OneRank=it->second;
            }
        }
        for(auto it=Wc.begin();it!=Wc.end();it++){
            if(it->first == 4){
                White.isFour=true;   
                White.FourRank=it->second;
            }
            else if(it->first==3){
                White.isThree=true;
                White.ThreeRank=it->second;
                if(White.isPair)
                    White.isFullHouse=true;
            }
            else if(it->first==2){
                if(White.isThree){
                    White.isFullHouse=true;
                }
                else if(White.isPair){
                    White.isTwoPair=true;
                    White.TwoPairRank=it->second;
                }
                else{
                    White.isPair=true;
                    White.PairRank=it->second;
                }
            }
            else{
                if(White.isTwoPair)
                    White.OneRank=it->second;
            }
        }
        if((Black.isStraightFlash)||(White.isStraightFlash)){
            if(Black.isStraightFlash && !White.isStraightFlash)
                winner=2;
            else if(!Black.isStraightFlash && White.isStraightFlash)
                winner=1;
            else{
                if(Wc[0].second > Bc[0].second)
                    winner=1;
                else if(Wc[0].second<Bc[0].second)
                    winner=2;
                else
                    winner=0;
            }
        }
        else if(Black.isFour || White.isFour){
            if(Black.isFour && !White.isFour)
                winner=2;
            else if(!Black.isFour && White.isFour)
                winner=1;
            else{
                if(Black.FourRank==White.FourRank)
                    winner=0;
                else if(Black.FourRank<White.FourRank)
                    winner=1;
                else
                    winner=2;
            }
        }
        else if(Black.isFullHouse || White.isFullHouse){
            if(Black.isFullHouse && !White.isFullHouse)
                winner=2;
            else if(!Black.isFullHouse && White.isFullHouse)
                winner=1;
            else{
                if(Black.ThreeRank==White.ThreeRank)
                    winner=0;
                else if(Black.ThreeRank<White.ThreeRank)
                    winner=1;
                else
                    winner=2;
            }
        }
        else if(Black.isFlash || White.isFlash){
            if(Black.isFlash && !White.isFlash)
                winner=2;
            else if(!Black.isFlash && White.isFlash)
                winner=1;
            else{
                int i=0;
                while(i<Bc.size() && Bc[i].second==Wc[i].second)
                    i++;
                if(i==Bc.size())
                    winner=0;
                else if(Bc[i].second<Wc[i].second)
                    winner=1;
                else
                    winner=2;
            }
        }
        else if(Black.isStraight || White.isStraight){
            if(Black.isStraight && !White.isStraight)
                winner=2;
            else if(!Black.isStraight && White.isStraight)
                winner=1;
            else{
                if(Wc[0].second > Bc[0].second)
                    winner=1;
                else if(Wc[0].second < Bc[0].second)
                    winner=2;
                else
                    winner=0;
            }
        }
        else if(Black.isThree || White.isThree){
            if(Black.isThree && !White.isThree)
                winner=2;
            else if(!Black.isThree && White.isThree)
                winner=1;
            else{
                if(Black.ThreeRank==White.ThreeRank)
                    winner=0;
                else if(Black.ThreeRank<White.ThreeRank)
                    winner=1;
                else
                    winner=2;
            }
        }
        else if(Black.isTwoPair || White.isTwoPair){
            if(Black.isTwoPair && !White.isTwoPair){
                winner=2;
            }
            else if(!Black.isTwoPair && White.isTwoPair){
                winner=1;
            }
            else{
                int a,b,c,d,e,f;
                c=Black.OneRank;
                f=White.OneRank;
                if(Black.PairRank < Black.TwoPairRank){
                    a=Black.TwoPairRank;
                    b=Black.PairRank;
                }
                else{
                    a=Black.PairRank;
                    b=Black.TwoPairRank;
                }
                if(White.PairRank < White.TwoPairRank){
                    d=White.TwoPairRank;
                    e=White.PairRank;
                }
                else{
                    d=White.PairRank;
                    e=White.TwoPairRank;
                }
                if(a==d){
                    if(b==e){
                        if(c==f)
                            winner=0;
                        else{
                            if(c<f)
                                winner=1;
                            else
                                winner=2;
                        }
                    }
                    else{
                        if(b<e)
                            winner=1;
                        else
                            winner=2;
                    }
                }
                else{
                    if(a<d)
                        winner=1;
                    else
                        winner=2;
                }
            }
        }
        else if(Black.isPair || White.isPair){
            if(Black.isPair && !White.isPair){
                winner=2;
            }
            else if(!Black.isPair && White.isPair){
                winner=1;
            }
            else{
                if(Black.PairRank==White.PairRank){
                    int i=1;
                    while(i<Bc.size() && Bc[i].second==Wc[i].second)
                        i++;
                    if(i==Bc.size())
                        winner=0;
                    else if(Bc[i].second < Wc[i].second)
                        winner=1;
                    else
                        winner=2;
                }
                else{
                    if(Black.PairRank<White.PairRank)
                        winner=1;
                    else
                        winner=2;
                }
            }
        }
        else{
            int i=0;
            while(i<Bc.size() && Bc[i].second==Wc[i].second)
                i++;
            if(i==Bc.size())
                winner=0;
            else if(Bc[i].second<Wc[i].second)
                winner=1;
            else
                winner=2;
        }
        if(winner==0)
            cout<<"Tie."<<endl;
        else if(winner==1)
            cout<<"White wins."<<endl;
        else
            cout<<"Black wins."<<endl;
    }
}
