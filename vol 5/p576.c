#include<stdio.h>
#include<string.h>
char line[205];
int isVowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
        return 1;
    return 0;
}
int main(){
    int len,valid,invalidpos;
    while(fgets(line,sizeof line,stdin)){
        int syllable=0,i,l;
        len=strcspn(line,"\n");
        line[len]='\0';
        if(!strcmp(line,"e/o/i"))
            break;
        valid=1;
        l=1;
        for(i=0;i<len;i++){
            if(line[i]=='/'){
                if(l==1){
                    if(syllable!=5){
                        valid=0;
                        invalidpos=l;
                        break;
                    }
                    else
                        l++;
                }
                else{
                    if(syllable!=7){
                        valid=0;
                        invalidpos=l;
                        break;
                    }
                    else
                        l++;
                }
                syllable=0;
            }
            else{
                if(isVowel(line[i])){
                    if(i>0 && !isVowel(line[i-1])){
                        syllable++;
                    }
                    else if(i==0)
                        syllable++;
                }
            }
        }
        if(l==3 && syllable!=5){
            valid=0;
            invalidpos=3;
        }
        if(valid)
            puts("Y");
        else
            printf("%d\n",invalidpos);
    }
}
