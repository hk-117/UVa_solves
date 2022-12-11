#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?(a):(b)
double leak,fuelExRate,ratePerHk,maxCap;
double nextConsumption(double nextPos,double prevPos){
  return (leak+fuelExRate)*(nextPos-prevPos);
}
int main(){
  char line[30],dmy[30];
  double prevPos=0,nextPos,tmpConsumption=0;
  maxCap=-1.0;
  while(fgets(line,sizeof line,stdin)){
    sscanf(line,"%lf",&nextPos);
    if(strstr(line,"Goal") != NULL){
      tmpConsumption+=nextConsumption(nextPos,prevPos);
      maxCap=max(tmpConsumption,maxCap);
      printf("%.3lf\n",maxCap);
      maxCap=-1;
      prevPos=0;
      tmpConsumption=0;
      fuelExRate=0;
      leak=0;
    }
    else if(strstr(line,"Gas station")!=NULL){
      tmpConsumption+=nextConsumption(nextPos,prevPos);
      maxCap=max(tmpConsumption,maxCap);
      prevPos=nextPos;
      tmpConsumption=0;
    }
    else if(strstr(line,"Leak")!=NULL){
      tmpConsumption+=nextConsumption(nextPos,prevPos);
      leak+=1.0;
      prevPos=nextPos;
    }
    else if(strstr(line,"Mechanic")!=NULL){
      tmpConsumption+=nextConsumption(nextPos,prevPos);
      leak=0;
      prevPos=nextPos;
    }
    else{
      double tmp;
      sscanf(line,"%lf %s %s %lf",&tmp,dmy,dmy,&ratePerHk);
      tmpConsumption+= nextConsumption(nextPos,prevPos);
      prevPos=nextPos;
      fuelExRate=(ratePerHk/100.0);
    }
  }
}
