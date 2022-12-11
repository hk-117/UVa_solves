import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    while(N-- > 0){
      BigInteger a=sc.nextBigInteger();
      System.out.println(sqrtNewton(a));
      if(N>0)
        System.out.println();
    }
  }
  public static BigInteger sqrtNewton(BigInteger n){
    BigInteger a = BigInteger.ONE.shiftLeft(n.bitLength() / 2);
    boolean p_dec = false;
    for (;;) {
      BigInteger b = n.divide(a).add(a).shiftRight(1);
      if (a.compareTo(b) == 0 || a.compareTo(b) < 0 && p_dec)
         break;
      p_dec = a.compareTo(b) > 0;
      a = b;
    }
    return a;
  }
}
