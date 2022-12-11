import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger sum=BigInteger.ZERO,inp;
    while(true){
      inp=sc.nextBigInteger();
      if(inp.equals(BigInteger.ZERO)) break;
      sum=sum.add(inp);
    }
    System.out.println(sum);
  }
}
