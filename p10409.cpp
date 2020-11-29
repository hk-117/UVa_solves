#include<bits/stdc++.h>
using namespace std;
//0-->top,1-->north,2-->west,3-->east,4-->south,5-->bottom
int faces[]={1,2,3,4,5,6};
void northRotate(){
  int tmp=faces[0];
  faces[0]=faces[4];
  faces[4]=faces[5];
  faces[5]=faces[1];
  faces[1]=tmp;
}
void southRotate(){
  int tmp=faces[0];
  faces[0]=faces[1];
  faces[1]=faces[5];
  faces[5]=faces[4];
  faces[4]=tmp;
}
void westRotate(){
  int tmp=faces[0];
  faces[0]=faces[3];
  faces[3]=faces[5];
  faces[5]=faces[2];
  faces[2]=tmp;
}
void eastRotate(){
  int tmp=faces[0];
  faces[0]=faces[2];
  faces[2]=faces[5];
  faces[5]=faces[3];
  faces[3]=tmp;
}
int main(){
  int N;
  string cmd;
  while(cin>>N,N){
    for(int i=0;i<6;i++) faces[i]=i+1;
    for(int i=0;i<N;i++){
      cin>>cmd;
      if(cmd=="north"){
        northRotate();
      }
      else if(cmd=="south"){
        southRotate();
      }
      else if(cmd=="east"){
        eastRotate();
      }
      else{
        westRotate();
      }
    }
    cout<<faces[0]<<endl;
  }
}
