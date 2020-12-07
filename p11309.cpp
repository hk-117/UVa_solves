#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string st){
  int sz=st.size();
  for(int i=0;i<sz/2;i++){
    if(st[i]!=st[sz-1-i])
      return false;
  }
  return true;
}
int main(){
  int T,a,b;
  scanf("%d",&T);
  while(T--){
    scanf("%d:%d",&a,&b);
    b++;
    bool found=false;
    string tmp;
    int tp;
    for(int i=a;i<=23 && !found;i++){
      int j;
      if(i>a) j=0;
      else j=b;
      for(;j<60 && !found;j++){
        tmp=to_string(i);
        if(i>0 && j<10){
          tmp+="0"+to_string(j);
        }
        else{
          tmp+=to_string(j);
        }
        tp=atoi(tmp.c_str());
        tmp=to_string(tp);
        if(isPalindrome(tmp)){
          printf("%02d:%02d\n",i,j);
          found=true;
        }
      }
    }
    if(!found){
      printf("00:00\n");
    }
  }
}
