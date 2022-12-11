#include<bits/stdc++.h>
#define Z(it,seq,c) for(auto it=seq.begin();it!=seq.end();it+=c)
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<string,pair<int,int>> pp;
typedef vector<pp> vpp;

int main(){
   bool ignored=false;
   int ttln=0;
   string inp;
   vector<string> dmw,titles;
   vpp keywords;
   while(getline(cin,inp)){
       if(inp=="::"){
           ignored=true;
           continue;
       }
       if(!ignored)
           dmw.PB(inp);
       else{
           Z(it,inp,1){
               if( *it >= 65 && *it <=90)
                   *it +=32;
           }
           titles.PB(inp);
           stringstream str(inp);
           string word;
           int word_count=0;
           while(str>>word){
               word_count++;
               auto it= find(dmw.begin(),dmw.end(),word);
               if(it== dmw.end()){
                   Z(et,word,1)
                       *et -= 32;
                   keywords.PB(MP(word,MP(ttln,word_count)));
               }
           }
           ttln++;
       }
   }
   sort(keywords.begin(),keywords.end());
   Z(it,keywords,1){
       string printable=titles[it->second.first];
       int omit_spaces= it->second.second -1;
       int replace_pos=0;
       while(omit_spaces--){
           replace_pos= printable.find(" ",replace_pos+1);
       }
       if(!replace_pos){
           printable.replace(replace_pos,it->first.size(),it->first);
       }
       else
           printable.replace(replace_pos+1,it->first.size(),it->first);
       cout<<printable<<endl;
   }

}
