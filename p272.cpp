#include<bits/stdc++.h>
#define FLUSH while(getchar() != '\n');
using namespace std;
int main(){
        ios::sync_with_stdio(false);
        char str;
        int count=1;
        while(scanf("%c",&str)!=EOF){
                if(str=='"' && count==1){
                        cout<<"``";
                        count++;
                }
                else if((str=='"') && count==2){
                        cout<<"''";
                        count--;
                }
                else{
                        cout<<str;
                }
        }
        return 0;
}
