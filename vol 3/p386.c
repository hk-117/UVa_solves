#include<stdio.h>
int main(){
    int a,b,c,d,i,j,k,l;
    for(i=2;i<=200;i++){
        a=i*i*i;
        for(j=2;j<=i;j++){
            b=j*j*j;
            if(b>a)
                break;
            for(k=j+1;k<=i;k++){
                c=k*k*k;
                if(b+c>a)
                    break;
                for(l=k+1;l<=i;l++){
                    d=l*l*l;
                    if(b+c+d>a)
                        break;
                    if(b+c+d==a){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                    }
                }
            }
        }
    }
}
