#include<stdio.h>
#include<string.h>
int vowl(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return 1;
    else
        return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int len1,len2,i;
        char name1[25],name2[25];
        scanf("%s",name1);
        getchar();
        scanf("%s",name2);
        getchar();
        len1=strlen(name1);
        len2=strlen(name2);
        if(len1==len2){
            int flg=1;
            for(i=0;i<len1 && flg;i++){
                if(!vowl(name1[i])){
                    if(name1[i] != name2[i])
                        flg=0;
                }
            }
            if(flg)
                puts("Yes");
            else
                puts("No");
        }
        else{
            puts("No");
        }
    }
}
