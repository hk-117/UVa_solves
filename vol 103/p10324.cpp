#include<iostream>

using namespace std;
int main(){
        string str;
        int cas=0;
        while(getline(cin,str),str.length()!=0){
                cas++;
                long int n,i,j,start,end;
                cin>>n;
                cout<<"Case "<<cas<<":\n";
                while(n--){
                        cin>>i>>j;
                        if(i<j){
                                start=i;
                                end=j;
                        }
                        else{
                                start=j;
                                end=i;
                        }
                        char c=str[start];
                        bool possible=true;
                        for(int tmp=start;tmp<=end;tmp++){
                                if(str[tmp] != c){
                                        possible=false;
                                        break;
                                }
                        }
                        if(possible)
                                cout<<"Yes\n";
                        else
                                cout<<"No\n";
                }
                cin.ignore();
        }
}
