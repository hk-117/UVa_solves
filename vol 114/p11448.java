import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int t=sc.nextInt();
    BigInteger A,B;
    while(t-- > 0){
      A=sc.nextBigInteger();
      B=sc.nextBigInteger();
      System.out.println(A.subtract(B));
    }
  }
}
