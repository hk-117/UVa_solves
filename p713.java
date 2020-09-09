import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int N=sc.nextInt();
    while(N>0){
      N--;
      BigInteger a,b,sum;
      a=sc.nextBigInteger();
      b=sc.nextBigInteger();
      a=new BigInteger(revString(a.toString()));
      b=new BigInteger(revString(b.toString()));
      sum= a.add(b);
      sum= new BigInteger(revString(sum.toString()));
      System.out.println(sum);
    }
  }
  public static String revString(String st){
    StringBuilder sb= new StringBuilder(st);
    sb.reverse();
    return sb.toString();
  }
}
