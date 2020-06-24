#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define Dict map<int,set<string>>
using namespace std;
void tokenize(string &pdescrip, map<string,bool> &seen){
    string word;
    for(int i=0;i<pdescrip.size();i++){
        if((pdescrip[i]>='a' && pdescrip[i]<='z')||(pdescrip[i]>='A' && pdescrip[i]<='Z')){
            word+= pdescrip[i];
        }
        else{
            seen[word]=true;
            word="";
        }
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int c;
        cin>>c;
        map<string,int> necessary;
        map<int,string> seq;
        Dict words;
        R(i,1,c+1,1){
            string s;
            int w,nece;
            cin>>s>>w>>nece;
            necessary[s]=nece;
            seq[i]=s;
            while(w--){
                string key;
                cin>>key;
                words[i].insert(key);
            }
        }
        map<string,bool> seen;
        vector<int> categories;
        string pdescrip,line;
        cin.ignore();
        while(getline(cin,line),line.size()!=0){
            pdescrip+= line+" ";
        }
        tokenize(pdescrip,seen);
        R(i,1,c+1,1){
            int freq=0;
            for(auto it=words[i].begin();it!=words[i].end();it++){
                if(seen[*it])
                    freq++;
            }
            if(freq>= necessary[seq[i]]){
                categories.push_back(i);
            }
        }
        if(!categories.size())
            cout<<"SQF Problem."<<endl;
        else{
            R(i,0,categories.size(),1){
                cout<<seq[categories[i]];
                if(i!=categories.size()-1)
                    cout<<",";
            }
            cout<<endl;
        }
    }
}
