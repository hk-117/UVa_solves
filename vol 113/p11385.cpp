#include<bits/stdc++.h>
using namespace std;
vector<long long int> fib(45,0);
int main(){
  int T;
  long int lim= 2147483648;
  scanf("%d",&T);
  fib[0]=1;
  fib[1]=2;
  long int n=1,sm=3;
  while( sm < lim ){
    n++;
    fib[n]=sm;
    sm= fib[n]+fib[n-1];
  }
  while(T--){
    int N,tmp;
    string msg;
    cin>>N;
    vector<int> NMS(N);
    for(int i=0;i<N;i++){
      cin>>tmp;
      NMS[i]=tmp;
    }
    getchar();
    getline(cin,msg);
    vector<pair<int,char>> charMap;
    for(int i=0,j=0;i<msg.size();i++){
      if(isalpha(msg[i]) && isupper(msg[i])){
        charMap.push_back(make_pair(NMS[j++],msg[i]));
      }
      if(j==N)
        break;
    }
    sort(charMap.begin(),charMap.end());
    int i=0,j=0;
    string res;
    while(i<N){
      if(charMap[i].first==fib[j]){
        res+=charMap[i++].second;
        j++;
      }
      else{
        res+=' ';
        j++;
      }
    }
    while(res[res.size()-1]==' '){
      res.erase(res.end()-1);
    }
    cout<<res<<endl;
  }
}
