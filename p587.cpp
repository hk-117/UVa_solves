#include<bits/stdc++.h>
using namespace std;
int main(){
  char line[250];
  int mp=0,len;
  while(fgets(line,sizeof line,stdin)){
    len= strcspn(line,"\n");
    line[len]='\0';
    if(strcmp(line,"END")==0) break;
    double x=0,y=0;
    char *p= strtok(line,",.");
    while(p!=NULL){
      char *wrd= p;
      int stp=atoi(wrd);
      double step=(double)stp;
      if(strstr(wrd,"NW")!=NULL){
        step=sqrt((step*step)/2);
        x-=step;
        y+=step;
      }
      else if(strstr(wrd,"NE")!=NULL){
        step=sqrt((step*step)/2);
        x+=step;
        y+=step;
      }
      else if(strstr(wrd,"SW")!=NULL){
        step=sqrt((step*step)/2);
        x-=step;
        y-=step;
      }
      else if(strstr(wrd,"SE")!=NULL){
        step=sqrt((step*step)/2);
        x+=step;
        y-=step;
      }
      else if(strchr(wrd,'N')!=NULL){
        y+=step;
      }
      else if(strchr(wrd,'S')!=NULL){
        y-=step;
      }
      else if(strchr(wrd,'E')!=NULL){
        x+=step;
      }
      else{
        x-=step;
      }
      p=strtok(NULL,",.");
    }
    printf("Map #%d\n",++mp);
    printf("The treasure is located at (%.3lf,%.3lf).\n",x,y);
    printf("The distance to the treasure is %.3lf.\n",sqrt(x*x+y*y));
    puts("");
  }
}
