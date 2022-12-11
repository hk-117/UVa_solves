#include<bits/stdc++.h>
using namespace std;
map<string,int>Num,Dsk,Pfix;
void makeMap(){
    vector<string> V={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    vector<string> V2={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    for(int i=0;i<20;i++){
        Num[V[i]]=i;
    }
    for(int i=0;i<8;i++){
        Dsk[V2[i]]= (i+2)*10;
    }
    Pfix["thousand"]=1000;Pfix["million"]=1000000;
}
int main(){
    string line;
    makeMap();
    while(getline(cin,line)){
        bool neg=false;
        stringstream ss(line);
        string nm,w;
        long long res=0,D=0;
        while(ss>>w){
            if(w=="negative")
                neg=true;
            else{
                if(Num.find(w) != Num.end()){
                    D+=Num[w];
                }
                if(Dsk.find(w) != Dsk.end()){
                    D += Dsk[w];
                }
                if(w=="hundred"){
                    D= D*100;
                }
                if(Pfix.find(w) != Pfix.end()){
                    res+= D* Pfix[w];
                    D=0;
                }
            }
        }
        if(D!=0){
            res+=D;
        }
        if(neg)
            cout<< -res <<endl;
        else
            cout<< res <<endl;
    }
}
