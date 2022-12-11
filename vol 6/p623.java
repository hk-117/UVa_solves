import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger N;
    while(sc.hasNext()){
      N=sc.nextBigInteger();
      BigInteger A=N;
      BigInteger fct=BigInteger.ONE;
      while(!N.equals(BigInteger.ZERO)){
        fct=fct.multiply(N);
        N=N.subtract(BigInteger.ONE);
      }
      System.out.println(A+"!");
      System.out.println(fct);
    }
  }
}
