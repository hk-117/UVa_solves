import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    while(N-- > 0){
      String a=sc.next();
      char c= sc.next().charAt(0);
      String b=sc.next();
      BigInteger n1= new BigInteger(a,16),n2=new BigInteger(b,16);
      BigInteger res;
      if(c=='+') res= n1.add(n2);
      else res= n1.subtract(n2);
      a=n1.toString(2);
      b=n2.toString(2);
      for(int i=1;i<= 13-(a.length());i++){
        System.out.print("0");
      }
      System.out.print(a+ " "+c+" ");
      for(int i=1;i<= 13-(b.length());i++){
        System.out.print("0");
      }
      System.out.println(b+" = "+res);
    }
  }
}
