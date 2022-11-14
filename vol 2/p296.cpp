#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
vector<string> allGuess;
struct Guess{
    string code;
    int right,wrong;
};

void generateGuess(){
    for(int i=0;i<10000;i++){
        char tmp[10];
        sprintf(tmp,"%04d",i);
        allGuess.push_back(string(tmp));
    }
}

bool isSame(string s,Guess g){
    map<char,int> tmpg,tmps;
    int r = 0, w = 0;
    for(int i=0;i<4;i++){
        if(s[i]==g.code[i]){
            r++;
        }
        else{
            tmpg[g.code[i]]++;
            tmps[s[i]]++;
        }
    }
    for(auto it = tmpg.begin();it!=tmpg.end();it++){
        if(tmps[it->first]){
            w+= min(tmps[it->first],it->second);
        }
    }
    if(g.right == r && g.wrong==w)
        return true;
    return false;
}

void checkValid(vector<Guess>& Guesses){
    vector<string> possible;
    for(int i=0;i<10000;i++){
        bool issame = true;
        for(int j=0;j<Guesses.size() && issame;j++){
            if(!isSame(allGuess[i],Guesses[j])){
                issame = false;
            }
        }
        if(issame){
            possible.push_back(allGuess[i]);
        }
        if(possible.size()>1){
            printf("indeterminate\n");
            return;
        }
    }
    if(possible.size()==0){
        printf("impossible\n");
    }
    else{
        printf("%s\n",possible[0].c_str());
    }
}
int main(){
    int t;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    generateGuess();
    scanf("%d",&t);
    while(t--){
        int g;
        vector<Guess> Guesses;
        string inp;
        int r,w;
        scanf("%d",&g);
        for(int i=0;i<g;i++){
            cin>>inp;
            scanf("%d/%d",&r,&w);
            Guess tmp;
            tmp.code = inp;
            tmp.right = r;
            tmp.wrong = w;
            Guesses.push_back(tmp);
        }
        checkValid(Guesses);
    }
}
