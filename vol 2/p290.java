import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(sc.hasNext()){
      String inp=sc.next();
      for(int i=15;i>=2;i--){
        if(i==15){
          if(!legalBase(inp,i)){
            System.out.print("?");
          }
          else{
            if(isPalindrome(inp))
              System.out.print("0");
            else
              System.out.print(findSteps(inp,i));
          }
        }
        else{
          if(!legalBase(inp,i)){
            System.out.print(" ?");
          }
          else{
            if(isPalindrome(inp))
              System.out.print(" 0");
            else
              System.out.print(" "+findSteps(inp,i));
          }
        }
      }
      System.out.println();
    }
  }
  public static boolean legalBase(String nm,int curBase){
    int digVal;
    char c;
    for(int i=0;i<nm.length();i++){
      c = nm.charAt(i);
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
      else{
        digVal=c-'0';
      }
      if(digVal>=curBase)
        return false;
    }
    return true;
  }
  public static int findSteps(String nm,int Bs){
    int cnt=0;
    while(true){
      cnt++;
      StringBuilder st=new StringBuilder(nm);
      BigInteger a=new BigInteger(st.toString(),Bs);
      BigInteger b=new BigInteger(st.reverse().toString(),Bs);
      nm = (a.add(b)).toString(Bs);
      if(isPalindrome(nm)){
        return cnt;
      }
    }
  }
  public static boolean isPalindrome(String num){
    for(int i=0;i<(num.length())/2 ;i++){
      if(num.charAt(i) != num.charAt(num.length()-1-i))
        return false;
    }
    return true;
  }
}
