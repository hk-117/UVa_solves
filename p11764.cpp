#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,cas=1;
    cin>>T;
    while(T--){
        int walls;
        cin>>walls;
        int heights[walls];
        for(int i=0;i<walls;i++){
            cin>>heights[i];
        }
        int high=0,low=0;
        if(walls==1){
            cout<<"Case "<< cas++ <<": "<<high<<" "<<low<<"\n";
        }
        else{
            for(int i=0;i<walls-1;i++){
                if(heights[i+1]>heights[i])
                    high++;
                else if(heights[i+1]<heights[i])
                    low++;
                else
                    continue;
            }
            cout<<"Case "<< cas++ <<": "<<high<<" "<<low<<"\n";
        }

    }
}
