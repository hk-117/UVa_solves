#include<bits/stdc++.h>
#define EPS 1e-6
#define PI acos(-1.0)
using namespace std;
double hypot(double dx,double dy){
  return sqrt(dx*dx+dy*dy);
}
struct point{
  double x,y;
  point(){x=y=0.0;}
  point(double _x,double _y): x(_x),y(_y){}
  bool operator < (point other) const{
    if(fabs(x-other.x)>EPS)
      return x<other.x;
    return y<other.y;
  }
  bool operator == (point other) const{
    return ((fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS));
  }
};
double dist(point p1,point p2){
  return hypot(p1.x-p2.x,p1.y-p2.y);
}
double DEG_to_RAD(double theta){
  return (theta*PI)/180.0;
}
point rotate(point p,double theta){
  double rad=DEG_to_RAD(theta);
  return point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}
struct line{
  double a,b,c;
};
void pointsToLine(point p1,point p2,line &l){
  if(fabs(p1.x-p2.x)<EPS){
    l.a=1.0;
    l.b=0.0;
    l.c= -p1.x;
  }
  else{
    l.a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
    l.b=1.0;
    l.c=-(double) (l.a*p1.x)-p1.y;
  }
}
bool areParallel(line l1,line l2){
  return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
}
bool areSame(line l1,line l2){
  return areParallel(l1,l2) && (fabs(l1.c-l2.c)<EPS);
}
bool areIntersect(line l1,line l2,point &p){
  if(areParallel(l1,l2)) return false;
  p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
  if(fabs(l1.b)>EPS) p.y=-(l1.a*p.x+l1.c);
  else p.y=-(l2.a*p.x+l2.c);
  return true;
}
int main(){
  int N,x1,y1,x2,y2,x3,y3,x4,y4;
  cin>>N;
  puts("INTERSECTING LINES OUTPUT");
  while(N--){
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    line l1,l2;
    point p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4),pi;
    pointsToLine(p1,p2,l1);
    pointsToLine(p3,p4,l2);
    if(areIntersect(l1,l2,pi)){
      printf("POINT %.2lf %.2lf\n",pi.x,pi.y);
    }
    else{
      if(areSame(l1,l2)){
        puts("LINE");
      }
      else
        puts("NONE");
    }
  }
  puts("END OF OUTPUT");
}
