#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define sq(a) (a)*(a)
typedef struct{
  int x,y;
} Point;
Point Points[1005];
int n,d;
int cmp(const void *ac,const void *bc){
  Point *a= (Point*) ac;
  Point *b= (Point*) bc;
  if(a->x==b->x)
    return a->y - b->y;
  return a->x - b->x;
}
double dist(Point a,Point b){
  return sqrt(sq(a.x-b.x)+ sq(a.y-b.y));
}
Point maxLastCovered(int lastPos){
  int i,j,range,l;
  Point maxLastCov;
  range= (int) sqrt(d*d - sq(Points[lastPos].y)) +Points[lastPos].x;
  maxLastCov.x= -1;
  l=Points[lastPos].x;
  for(i=l;i<=range;i++){
    int cov=0;
    Point cur;
    cur.x=i;
    cur.y=0;
    for(j=lastPos;j<n;j++){
      double dista=dist(cur,Points[j]);
      if(dista<=d){
        cov++;
      }
      else{
        break;
      }
    }
    if(maxLastCov.x <= cov){
      maxLastCov.x=cov;
      maxLastCov.y=j;
    }
  }
  return maxLastCov;
}
int main(){
  int tc=0;
  while(scanf("%d %d",&n,&d)==2 && (n||d)){
    int Possible=1,i,minRadar=0,totalCovered=0;
    Point maxLastCov;
    for(i=0;i<n;i++){
      scanf("%d %d",&Points[i].x,&Points[i].y);
      if(abs(Points[i].y)>d)
        Possible=0;
    }
    if(!Possible){
      printf("Case %d: -1\n",++tc);
      continue;
    }
    qsort(Points,n,sizeof Points[0],cmp);
    maxLastCov.y=0;
    while(totalCovered<n){
      maxLastCov=maxLastCovered(maxLastCov.y);
      totalCovered+=maxLastCov.x;
      minRadar++;
    }
    printf("Case %d: %d\n",++tc,minRadar);
  }
}
