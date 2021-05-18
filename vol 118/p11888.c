#include<stdio.h>
#include<string.h>
#define MAX 200005

char P[MAX],T[MAX],tmp[MAX];
int b[MAX],m;

void kmpPreprocess(){
    int i=1,j=0;
    while(i<m){
        while(j>0 && P[i]!=P[j]){
            j=b[j-1];
        }
        if(P[i]==P[j])
            j++;
        b[i]=j;
        i++;
    }
}

int kmpSearch(){
    int i=0,j=0;
    while(i<m){
        if(T[i]==P[j]){
            i++;
            j++;
        }
        else if(j>0){
            j=b[j-1];
        }
        else
            i++;
    }
    return j;
}

int isPalindrome(char *str){
    int i,len=strlen(str);
    for(i=(len-1)/2;i>=0;i--){
        if(str[i]!=str[len-1-i])
            return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int i,j,pos,alsame=1;
        char t;
        scanf("%s",T);
        m=strlen(T);
        t=T[0];
        for(i=m-1,j=0;i>=0;i--){
            P[j++]=T[i];
            if(i!=0 && T[i]!=t)
                alsame=0;
        }
        P[m]='\0';
        kmpPreprocess();
        if(isPalindrome(T)){
            if(m>1 && alsame)
                puts("alindrome");
            else if(m>1 && (m%2==0) && isPalindrome(T+(m/2)))
                puts("alindrome");
            else
                puts("palindrome");
        }
        else{
            pos=kmpSearch();
            if(isPalindrome(P+pos))
                puts("alindrome");
            else{
                int tpos;
                strcpy(tmp,P);
                strcpy(P,T);
                strcpy(T,tmp);
                kmpPreprocess();
                tpos=kmpSearch();
                if(isPalindrome(P+tpos))
                    puts("alindrome");
                else
                    puts("simple");
            }
        }
    }
}
