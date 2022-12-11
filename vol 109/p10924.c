#include<stdio.h>
#include<string.h>
int mask[1500],vals[150];
void createPrime(){
  int i,j,sieve_size=1500;
  memset(mask,0,sizeof mask);
  mask[0]=1;
  mask[1]=0;
  for(i=2;i<=sieve_size;i++)
    if(!mask[i])
      for(j=i*i;j<=sieve_size;j+=i) mask[j]=1;
}
void createMap(){
  int i;
  char alph[53]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(i=0;i<53;i++){
    vals[alph[i]]=i+1;
  }
}
int main(){
  char word[25];
  createPrime();
  createMap();
  while(fgets(word,sizeof word,stdin)){
    int i,sum=0,len;
    len=strcspn(word,"\n\r");
    word[len]='\0';
    for(i=0;i<len;i++){
      sum+= vals[word[i]];
    }
    if(!mask[sum])
      puts("It is a prime word.");
    else
      puts("It is not a prime word.");
  }
}
