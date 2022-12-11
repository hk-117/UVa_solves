#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int dig(int num){
        int sum=0;
        while(num>0){
                int digit=num%10;
                sum+=digit;
                num=num/10;
        }
        if(sum/10 ==0)
                return sum;
        else
                return dig(sum);
}
int main(){
        char name1[26],name2[26];
        while(scanf("%[^\n]\n%[^\n]\n",name1,name2)!=EOF){
                int l1,l2,sum1=0,sum2=0;
                l1=strlen(name1);
                l2=strlen(name2);
                for(int i=0; i<l1;i++){
                        if(isalpha(name1[i])){
                                if(isupper(name1[i]))
                                        sum1+=name1[i]-'A'+1;
                                else
                                        sum1+=name1[i]-'a'+1;
                        }

                }
                for(int i=0; i<l2;i++){
                        if(isalpha(name2[i])){
                                if(isupper(name2[i]))
                                        sum2+=name2[i]-'A'+1;
                                else
                                        sum2+=name2[i]-'a'+1;
                        }

                }
                float ratio;
                int digit1,digit2;
                digit1=dig(sum1);
                digit2=dig(sum2);
                if(digit1<digit2)
                        ratio=digit1*100.0/digit2;
                else
                        ratio=digit2*100.0/digit1;
                printf("%.2f %%\n",ratio);
        }

}
