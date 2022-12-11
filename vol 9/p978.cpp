#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int b,sg,sb;
        cin>>b>>sg>>sb;
        multiset<int,greater<int>> green,blue;
        while(sg--){
            int power;
            cin>>power;
            green.insert(power);
        }
        while(sb--){
            int power;
            cin>>power;
            blue.insert(power);
        }
        multiset<int,greater<int>> gd,bd;
        while((blue.size()||bd.size()) && (green.size()||gd.size())){
            for(int i=0;i<b;i++){
                if(blue.size() && green.size()){
                    int g= *green.begin(),bl=*blue.begin();
                    if(g==bl){
                        blue.erase(blue.begin());
                        green.erase(green.begin());
                    }
                    else if(g>bl){
                        gd.insert(g-bl);
                        blue.erase(blue.begin());
                        green.erase(green.begin());
                    }
                    else{
                        bd.insert(bl-g);
                        blue.erase(blue.begin());
                        green.erase(green.begin());
                    }
                }
                else{
                    break;
                }
            }
            green.insert(gd.begin(),gd.end());
            blue.insert(bd.begin(),bd.end());
            gd.clear();
            bd.clear();
        }
        green.insert(gd.begin(),gd.end());
        blue.insert(bd.begin(),bd.end());
        if(green.size()==0 && blue.size()==0){
            cout<<"green and blue died"<<endl;
        }
        else if(!green.size()){
            cout<<"blue wins"<<endl;
            for(auto it=blue.begin();it!=blue.end();it++)
                cout<< *it <<endl;
        }
        else{
            cout<<"green wins"<<endl;
            for(auto it=green.begin();it!=green.end();it++)
                cout<< *it <<endl;
        }
        if(tc)
            cout<<endl;
    }
}
