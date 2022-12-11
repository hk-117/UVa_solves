#include<stdio.h>
#include<string.h>
char St[260];
int sz,nv;
int findOneS(int i){
  int status;
  if(i>=sz)
    return 0;
  if(St[i]=='N'){
    return findOneS(i+1);
  }
  else if(St[i]=='C'||St[i]=='D'||St[i]=='E'||St[i]=='I'){
    status= findOneS(i+1);
    return (status && findOneS(nv+1));
  }
  else{
    if(St[i]>='p' && St[i] <='z'){
      nv=i;
      return 1;
    }
  }
}
int main(){
  int vld,i,ot;
  while(fgets(St,sizeof St,stdin)){
    sz=strcspn(St,"\n");
    i=0;
    ot=0;
    if(St[i]=='N'){
      vld=findOneS(i+1);
    }
    else if(St[i]=='C'||St[i]=='D'||St[i]=='E'||St[i]=='I'){
      vld=findOneS(i+1);
      vld= vld && findOneS(nv+1);
    }
    else{
      if(sz==1)
        puts("YES");
      else
        puts("NO");
      ot=1;
    }
    if(!ot){
      if(vld==1 && nv+1==sz)
        puts("YES");
      else
        puts("NO");
    }
  }
}
