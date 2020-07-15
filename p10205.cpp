#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
char values[]="23456789TJQKA";
char suits[]="CDHS";
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
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        int numShuffle,visualCues;
        vector<int>normalOrder(52),tmpOrder(52);
        R(i,0,52,1)
            normalOrder[i]=i;
        cin>>numShuffle;
        int shuffleOrders[numShuffle][52];
        R(i,0,numShuffle,1){
            R(j,0,52,1){
                cin>>shuffleOrders[i][j];
            }
        }
        string cues;
        cin.ignore();
        while(getline(cin,cues),cues.size()){
            sscanf(cues.c_str(),"%d",&visualCues);
            R(i,0,52,1){
                tmpOrder[i]= normalOrder[shuffleOrders[visualCues-1][i]-1];
            }
            normalOrder=tmpOrder;
        }
        R(i,0,52,1){
            if(value(normalOrder[i])=='A'){
                printf("Ace of ");
            }
            else if(value(normalOrder[i])=='K'){
                printf("King of ");
            }
            else if(value(normalOrder[i])=='Q'){
                printf("Queen of ");
            }
            else if(value(normalOrder[i])=='J'){
                printf("Jack of ");
            }
            else if(value(normalOrder[i])=='T'){
                printf("10 of ");
            }
            else{
                printf("%c of ",value(normalOrder[i]));
            }
            if(suit(normalOrder[i])=='C'){
                puts("Clubs");
            }
            else if(suit(normalOrder[i])=='D'){
                puts("Diamonds");
            }
            else if(suit(normalOrder[i])=='H'){
                puts("Hearts");
            }
            else{
                puts("Spades");
            }
        }
        if(tc)
            puts("");
    }
}
