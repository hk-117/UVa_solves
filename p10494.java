import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(sc.hasNext()){
      BigInteger a=sc.nextBigInteger();
      char op= sc.next().charAt(0);
      int d= sc.nextInt();
      if(op=='%'){
        System.out.println(a.mod(BigInteger.valueOf(d)));
      }
      else{
        System.out.println(a.divide(BigInteger.valueOf(d)));
      }
    }
  }
}
