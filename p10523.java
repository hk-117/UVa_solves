import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(sc.hasNext()){
      BigInteger sm=BigInteger.ZERO,A;
      int N=sc.nextInt();
      A=sc.nextBigInteger();
      for(int i=1;i<=N;i++){
        BigInteger tmp= A.pow(i);
        sm= sm.add(tmp.multiply(BigInteger.valueOf(i)));
      }
      System.out.println(sm);
    }
  }
}
