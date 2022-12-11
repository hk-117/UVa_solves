#include<stdio.h>
#include<string.h>
#include<math.h>
#define EPS 1e-9
double Duration[100];
void makeMap(){
  Duration['W']=1;
  Duration['H']=1.0/2.0;
  Duration['Q']=1.0/4.0;
  Duration['E']=1.0/8.0;
  Duration['S']=1.0/16.0;
  Duration['T']=1.0/32.0;
  Duration['X']=1.0/64.0;
}
double evalNotes(char *Measure){
  double val=0;
  int i;
  for(i=0;Measure[i]!='\0';i++){
    val+=Duration[Measure[i]];
  }
  return val;
}
int main(){
  char line[250];
  int Cnt,len;
  double sumNote;
  makeMap();
  while(fgets(line,sizeof line,stdin)){
    char *p;
    len=strcspn(line,"\n\r");
    line[len]='\0';
    if(strcmp(line,"*")==0){
      break;
    }
    Cnt=0;
    p=strtok(line,"/");
    while(p!=NULL){
      sumNote=evalNotes(p);
      if(fabs(sumNote-1)<EPS){
        Cnt++;
      }
      p=strtok(NULL,"/");
    }
    printf("%d\n",Cnt);
  }
}
