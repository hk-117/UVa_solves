import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int tc;
    tc=sc.nextInt();
    while(tc>0){
      tc--;
      BigInteger P,N;
      N=sc.nextBigInteger();
      P=sc.nextBigInteger();
      System.out.println(P.mod(N));
    }
  }
}
