#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define loose 0
#define win 1
#define chicken 2
using namespace std;
int main(){
    int r;
    while(cin>>r,r!=-1){
        string sol,gs;
        cin>>sol>>gs;
        bool wrongGuess[26]={false},rightGuess[sol.size()]={false};
        int wrongCount=0,status=chicken;
        R(i,0,gs.size(),1){
            bool found=false;
            R(j,0,sol.size(),1){
                if(gs[i]==sol[j]){
                    found=true;
                    rightGuess[j]=true;
                }
            }
            if(count(rightGuess,rightGuess+(sol.size()),0)==0){
                status=win;
                break;
            }
            if(!found){
                if(!wrongGuess[gs[i]-'a']){
                    wrongCount++;
                    wrongGuess[gs[i]-'a']=true;
                }
            }
            if(wrongCount==7){
                status=loose;
                break;
            }
        }
        printf("Round %d\n",r);
        if(status==win)
            puts("You win.");
        else if(status==loose)
            puts("You lose.");
        else{
            puts("You chickened out.");
        }
    }
}
