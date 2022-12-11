#include<cstdio>
#include<cstring>
using namespace std;
void printFirst(const char* v){
    char c=243;
    printf("%-10s%so\n","eu",v); 
    printf("%-10s%sas\n","tu",v); 
    printf("%-10s%sa\n","ele/ela",v); 
    printf("n%cs       %samos\n",c,v); 
    printf("v%cs       %sais\n",c,v); 
    printf("%-10s%sam\n","eles/elas",v); 
}
void printSecond(const char* v){
    char c=243;
    printf("%-10s%so\n","eu",v); 
    printf("%-10s%ses\n","tu",v); 
    printf("%-10s%se\n","ele/ela",v); 
    printf("n%cs       %semos\n",c,v); 
    printf("v%cs       %seis\n",c,v); 
    printf("%-10s%sem\n","eles/elas",v); 
}
void printThird(const char* v){
    char c=243;
    printf("%-10s%so\n","eu",v); 
    printf("%-10s%ses\n","tu",v); 
    printf("%-10s%se\n","ele/ela",v); 
    printf("n%cs       %simos\n",c,v); 
    printf("v%cs       %sis\n",c,v); 
    printf("%-10s%sem\n","eles/elas",v); 
}
int main(){
    char va[35],vb[35];
    int nl=0;
    while(scanf("%s",va)==1){
        int len;
        getchar();
        fgets(vb,sizeof vb,stdin);
        len=strlen(va);
        vb[strcspn(vb,"\n")]='\0';
        if(nl)
            puts("");
        else
            nl=1;
        printf("%s (to %s)\n",va,vb);
        if(va[len-1]=='r' && va[len-2]=='a'){
            va[len-1]='\0';
            va[len-2]='\0';
            printFirst(va);
        }
        else if(va[len-1]=='r' && va[len-2]=='e'){
            va[len-1]='\0';
            va[len-2]='\0';
            printSecond(va);
        }
        else if(va[len-1]=='r' && va[len-2]=='i'){
            va[len-1]='\0';
            va[len-2]='\0';
            printThird(va);
        }
        else
            puts("Unknown conjugation");
    }
}
