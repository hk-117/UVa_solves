#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int cardValue(char value){
    if(value=='A'||value=='K'||value=='Q'||value=='J'||value=='T'){
        return 10;
    }
    else
        return (value-'0');
}
int main(){
    int t,tc=0;
    cin>>t;
    while(t--){
        tc++;
        deque<string>Cards;
        string cd;
        R(i,0,52,1){
            cin>>cd;
            Cards.push_front(cd);
        }
        int y=0;
        R(i,0,3,1){
            string topCard = *(Cards.begin()+25);
            Cards.erase(Cards.begin()+25);
            int cardVl= cardValue(topCard[0]);
            y+=cardVl;
            cardVl=10-cardVl;
            R(i,0,cardVl,1){
                topCard=*(Cards.begin()+25);
                Cards.erase(Cards.begin()+25);
            }
        }
        string targetCard = *(Cards.rbegin()+y-1);
        printf("Case %d: %s\n",tc,targetCard.c_str());
    }
}
