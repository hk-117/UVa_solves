import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger N;
    while(sc.hasNext()){
      N=sc.nextBigInteger();
      BigInteger A=N;
      BigInteger fct=BigInteger.ONE;
      if(N.equals(BigInteger.ZERO))
        fct=fct;
      else{
        while(!N.equals(BigInteger.ZERO)){
          fct=fct.multiply(N);
          N=N.subtract(BigInteger.ONE);
        }
      }
      String Rs=fct.toString();
      char c='0';
      for(int i=Rs.length()-1;i>=0;i--){
        if(Rs.charAt(i) != '0'){
          c=Rs.charAt(i);
          break;
        }
      }
      System.out.printf("%5d -> %c",A,c).println();
    }
  }
}
