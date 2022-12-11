import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    String line;
    char op;
    BigInteger res,a,b;
    long mx=2147483647;
    while(sc.hasNext()){
      line=sc.nextLine();
      Scanner sd=new Scanner(line);
      a=sd.nextBigInteger();
      op=sd.next().charAt(0);
      b=sd.nextBigInteger();
      System.out.println(line);
      if(BigInteger.valueOf(mx).compareTo(a) < 0){
        System.out.println("first number too big");
      }
      if(BigInteger.valueOf(mx).compareTo(b) < 0){
        System.out.println("second number too big");
      }
      if(op=='+') res=a.add(b);
      else res=a.multiply(b);
      if(BigInteger.valueOf(mx).compareTo(res) <0){
        System.out.println("result too big");
      }
    }
  }
}
