#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int columns;
        getchar();
        cin>>columns;
        int possible=1;
        int northest,southest,differences[columns];
        for(int i=0;i<columns;i++){
            cin>>northest>>southest;
            differences[i]=northest-southest;
        }
        for(int i=0;i<columns-1;i++){
            if(differences[i]!=differences[i+1]){
                possible=0;
                break;
            }
        }
        if(possible)
            cout<<"yes\n";
        else
            cout<<"no\n";
        if (t)
            cout<<"\n";
    }

}
