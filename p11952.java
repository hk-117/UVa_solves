import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    String a,b,res;
    char c;
    while(N-- > 0){
      a=sc.next();
      c=sc.next().charAt(0);
      b=sc.next();
      c=sc.next().charAt(0);
      res=sc.next();
      if(isOneBase(a) && isOneBase(b)){
        if(isOneBase(res) && (a.length()+b.length())==res.length()){
          System.out.println("1");
          continue;
        }
      }
      System.out.println(findRes(a,b,res));
    }
  }
  public static boolean isOneBase(String nm){
    for(int i=0;i<nm.length();i++){
      if(nm.charAt(i) != '1')
        return false;
    }
    return true;
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
  public static int findRes(String a,String b,String res){
    for(int i=2;i<=18;i++){
      if(legalBase(a,i) && legalBase(b,i)){
        BigInteger aint=new BigInteger(a,i);
        BigInteger bint=new BigInteger(b,i);
        String rs = (aint.add(bint)).toString(i);
        if(res.equals(rs)){
          return i;
        }
      }
    }
    return 0;
  }
}
