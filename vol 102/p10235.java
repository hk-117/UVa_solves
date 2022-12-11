import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(sc.hasNext()){
      BigInteger N=sc.nextBigInteger();
      String R= new StringBuffer(N.toString()).reverse().toString();
      BigInteger RN=new BigInteger(R);
      System.out.print(N+" is ");
      if(!N.isProbablePrime(10))
        System.out.println("not prime.");
      else if(!N.equals(RN) && RN.isProbablePrime(10))
        System.out.println("emirp.");
      else
        System.out.println("prime.");
    }
  }
}
