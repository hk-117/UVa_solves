import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int d=17;
    BigInteger A;
    while(true){
      A=sc.nextBigInteger();
      if(A.equals(BigInteger.ZERO)) break;
      if(A.mod(BigInteger.valueOf(d)).equals(BigInteger.ZERO)){
        System.out.println(1);
      }
      else
        System.out.println(0);
    }
  }
}
