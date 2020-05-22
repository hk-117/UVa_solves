#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
struct PR{
    string dept,title,first,last,street,hphone,wphone,cmail;
};
bool fnc(PR p1,PR p2){
    return p1.last < p2.last;
}
int main(){
    vector<PR> books;
    int depts;
    cin>>depts;
    cin.ignore();
    while(depts--){
        PR inp;
        string deptname,infos;
        getline(cin,deptname);
        while(getline(cin,infos)){
            if(infos.size()==0)
                break;
            inp.dept=deptname;
            stringstream ss(infos);
            string tmp;
            int t=0;
            while(ss.good()){
                getline(ss,tmp,',');
                if(t==0){
                    inp.title=tmp;
                }
                else if(t==1){
                    inp.first=tmp;
                }
                else if(t==2){
                    inp.last=tmp;
                }
                else if(t==3){
                    inp.street=tmp;
                }
                else if(t==4){
                    inp.hphone=tmp;
                }
                else if(t==5){
                    inp.wphone=tmp;
                }
                else{
                    inp.cmail=tmp;
                }
                t++;
            }
            books.push_back(inp);
        }
    }
    sort(books.begin(),books.end(),fnc);
    for(auto it=books.begin();it!=books.end();it++){
        R(i,1,41,1) cout<<"-";
        cout<<endl;
        cout<< it->title<<" "<< it->first <<" "<< it->last<<endl;
        cout<< it->street<<endl;
        cout<<"Department: "<< it->dept<<endl;
        cout<<"Home Phone: "<< it->hphone<<endl;
        cout<<"Work Phone: "<< it->wphone<<endl;
        cout<<"Campus Box: "<< it->cmail<<endl;
    }
}
