#include<stdio.h>
#include<string.h>
#include<ctype.h>
int Tbl[150];
char M[5][5];
void makeTable(char *p,int len){
    int i,j=0;
    memset(Tbl,-1,sizeof Tbl);
    for(i=0;i<len;i++){
        char c=toupper(p[i]);
        if(Tbl[c]==-1 && c!=' '){
            Tbl[c]=j++;
            M[Tbl[c]/5][Tbl[c]%5]=c;
        }
    }
    for(i='A';i<='Z';i++){
        if(Tbl[i]==-1 && i!='Q'){
            Tbl[i]=j++;
            M[Tbl[i]/5][Tbl[i]%5]=i;
        }
    }
}
void substitute(char c1,char c2){
    int rowa,rowb,cola,colb;
    if(c1==c2)
        c2='X';
    rowa=Tbl[c1]/5;
    rowb=Tbl[c2]/5;
    cola=Tbl[c1]%5;
    colb=Tbl[c2]%5;
    if(rowa==rowb){
        printf("%c",M[rowa][(cola+1)%5]);
        printf("%c",M[rowa][(colb+1)%5]);
    }
    else if(cola==colb){
        printf("%c",M[(rowa+1)%5][cola]);
        printf("%c",M[(rowb+1)%5][cola]);
    }
    else{
        printf("%c",M[rowa][colb]);
        printf("%c",M[rowb][cola]);
    }
}
void encrypt(char *p,int len){
    int i,j,nlen=0;
    char np[len];
    for(i=0;i<len;i++){
        if(isalpha(p[i]))
            np[nlen++]=toupper(p[i]);
    }
    np[nlen]='\0';
    i=0;
    while(i<nlen){
        if(i+1<nlen && np[i]==np[i+1]){
            substitute(np[i],'X');
            i++;
        }
        else if(i<nlen && i+1>=nlen){
            substitute(np[i],'X');
            i++;
        }
        else{
            substitute(np[i],np[i+1]);
            i+=2;
        }
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        char p[1005];
        int len;
        fgets(p,sizeof p,stdin);
        len=strcspn(p,"\n");
        p[len]='\0';
        makeTable(p,len);
        fgets(p,sizeof p,stdin);
        len=strcspn(p,"\n");
        p[len]='\0';
        encrypt(p,len);
    }
}
