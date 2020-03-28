#include<bits/stdc++.h>
using namespace std;

int main(){
    string song[]={
        "Happy",
        "birthday",
        "to",
        "you",
        
        "Happy",
        "birthday",
        "to",
        "you",
        
        "Happy",
        "birthday",
        "to",
        "Rujia",

        "Happy",
        "birthday",
        "to",
        "you"
    };
    int n;
    cin>>n;
    string peoples[n];
    for(int i=0;i<n;i++){
        cin>>peoples[i];
    }
    int upto=16,cycle=1;
    while(n>upto){
        upto+=16;
        cycle++;
    }
    int j=0;
    while(cycle--){
        for(int i=0;i<16;i++){
            cout<<peoples[j++]<<": "<<song[i]<<"\n";
            if(j==n)
                j=0;
        }

    }

}
