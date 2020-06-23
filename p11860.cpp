#include<bits/stdc++.h>
using namespace std;
void parse(string &document,map<string,int> &poses,int &unique_words,int &total_words,vector<int> &word_frequency,vector<int> &indices){
    char delim[]="`~1234567890-=!@#$%^&*()_+{[}]|:;\\\" '<,>.?/";
    char *tok= new char[document.size()+1];
    strcpy(tok,document.c_str());
    char *p= strtok(tok,delim);
    while(p!=NULL){
        string w(p);
        pair<map<string,int>::iterator,bool>res=poses.insert(make_pair(w,unique_words));
        indices.push_back(res.first->second);
        total_words++;
        if(res.second){
            word_frequency.push_back(0);
            unique_words++;
        }
        p=strtok(NULL,delim);
    }
}
int main(){
    int t,d=0;
    cin>>t;
    cin.ignore();
    while(t--){
        d++;
        vector<int> word_frequency,indices;
        map<string,int>poses;
        string document,inp;
        while(getline(cin,inp),inp!="END"){
            document+=inp+" ";
        }
        int unique_words=0,total_words=0;
        parse(document,poses,unique_words,total_words,word_frequency,indices);
        int min_p=0,min_q=total_words,all_words=0;
        for(int p=0,q=0;p<total_words && q<=total_words;){
            if(all_words==unique_words){
                if(q-p <min_q-min_p)
                    min_p=p,min_q=q;
                if(!--word_frequency[indices[p]])
                    all_words--;
                p++;
            }
            else{
                if(q<total_words && !word_frequency[indices[q]]++)
                    all_words++;
                q++;
            }
        }
        cout<<"Document "<<d<<": "<<min_p+1<<" "<<min_q<<endl;
    }
}
