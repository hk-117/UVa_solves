#include<bits/stdc++.h>
using namespace std;
int main(){
    int start,ending,distance1,distance2;
    while(scanf("%d%d",&start,&ending), (start!=-1 && ending!=-1)){
        if(start<ending){
            distance1=ending-start;
            distance2=start+(99-ending)+1;
            if(distance1<distance2)
                printf("%d\n",distance1);
            else
                printf("%d\n",distance2);
        }
        else{
            distance1=start-ending;
            distance2=(99-start)+(ending+1);
            if(distance1<distance2)
                printf("%d\n",distance1);
            else
                printf("%d\n",distance2);
        
        }

    }
    return 0;
}
