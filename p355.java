import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(sc.hasNext()){
      int curBase=sc.nextInt();
      int toBase=sc.nextInt();
      String nm= sc.next();
      if(!legalBase(nm,curBase)){
        System.out.println(nm+" is an illegal base "+curBase+" number");
      }
      else{
        BigInteger N= new BigInteger(nm,curBase);
        String cvt = N.toString(toBase).toUpperCase();
        System.out.println(nm+" base "+curBase+" = "+cvt+" base "+toBase);
      }
    }
  }
  public static boolean legalBase(String nm,int curBase){
    int digVal;
    char c;
    for(int i=0;i<nm.length();i++){
      c= nm.charAt(i);
      if(c=='A'){
        digVal=10;
      }
      else if(c=='B'){
        digVal=11;
      }
      else if(c=='C'){
        digVal=12;
      }
      else if(c=='D'){
        digVal=13;
      }
      else if(c=='E'){
        digVal=14;
      }
      else if(c=='F'){
        digVal=15;
      }
      else{
        digVal=c-'0';
      }
      if(digVal>=curBase)
        return false;
    }
    return true;
  }
}
