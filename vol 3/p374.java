import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger R,B,P,M;
    while(sc.hasNext()){
      B=sc.nextBigInteger();
      P=sc.nextBigInteger();
      M=sc.nextBigInteger();
      R= B.modPow(P,M);
      System.out.println(R);
    }
  }
}
