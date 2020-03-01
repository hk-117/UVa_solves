#include<bits/stdc++.h>
using namespace std;

long long toAnyBase(char num[],long long base,int len){
    int value=0,positional_weight=1;
    for(int i=len-1;i>=0;i--){
        if(num[i]>='0' && num[i]<='9'){
            value =value+ (num[i]-'0')*positional_weight;
        }
        else
            value=value + (num[i]-'A'+10)*positional_weight;
        
        positional_weight = positional_weight*base;
    }
    return value;
}

int main(){
    char X[50],Y[50];
    while(scanf("%s%s",X,Y)==2){
        int lenX,lenY,starting_baseX=1,starting_baseY=1;
        lenX=strlen(X);
        lenY=strlen(Y);
        for(int i=0;i<lenX;i++){
            if(X[i]>='0' && X[i]<='9'){
                starting_baseX =starting_baseX > (X[i]-'0') ? starting_baseX:(X[i]-'0');
            }
            else{
                starting_baseX=starting_baseX > (X[i]-'A'+10) ? starting_baseX:(X[i]-'A'+10);
            }
        }
        for(int i=0;i<lenY;i++){
            if(Y[i]>='0' && Y[i]<='9'){
                starting_baseY =starting_baseY > (Y[i]-'0') ? starting_baseY:(Y[i]-'0');
            }
            else{
                starting_baseY=starting_baseY > (Y[i]-'A'+10) ? starting_baseY:(Y[i]-'A'+10);
            }
        }
        starting_baseX++,starting_baseY++;
        int flag=0;
        while(starting_baseX<=36){
            flag=0;
            for(int i=starting_baseY;i<=36;i++){
                if(toAnyBase(X,starting_baseX,lenX)==toAnyBase(Y,i,lenY)){
                    printf("%s (base %d) = %s (base %d)\n", X, starting_baseX, Y, i);
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
            starting_baseX++;
        }
        if(!flag)
            printf("%s is not equal to %s in any base 2..36\n", X, Y);
    }
    return 0;
}
