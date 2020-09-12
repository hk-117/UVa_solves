import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    char c;
    while(true){
      c= sc.next().charAt(0);
      String org= sc.next(),tmp="0";
      if(c=='0' && org.equals("0")) break;
      for(int i=0;i<org.length();i++){
        if(org.charAt(i) != c) tmp= tmp+ org.charAt(i);
      }
      BigInteger A=new BigInteger(tmp);
      System.out.println(A);
    }
  }
}
