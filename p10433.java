import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger N;
    while(sc.hasNext()){
      String num= sc.next();
      N=new BigInteger(num);
      if(N.equals(BigInteger.ZERO) || N.equals(BigInteger.ONE)){
        System.out.println("Not an Automorphic number.");
        continue;
      }
      int dig=num.length();
      BigInteger sq= N.pow(2);
      String md= sq.toString();
      if(md.length() < dig){
        System.out.println("Not an Automorphic number.");
        continue;
      }
      md= md.substring(md.length()-dig);
      if(md.equals(num)){
        System.out.println("Automorphic number of "+dig+"-digit.");
      }
      else{
        System.out.println("Not an Automorphic number.");
      }
    }
  }
}
