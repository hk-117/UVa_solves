import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(true){
      BigInteger Num= sc.nextBigInteger();
      if(Num.compareTo(BigInteger.ZERO)<0) break;
      System.out.println(Num.toString(3));
    }
  }
}
