import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger N;
    while(true){
      N=sc.nextBigInteger();
      if(N.equals(BigInteger.ZERO)) break;
      BigInteger A=N;
      BigInteger fct=BigInteger.ONE;
      while(!N.equals(BigInteger.ZERO)){
        fct=fct.multiply(N);
        N=N.subtract(BigInteger.ONE);
      }
      System.out.println(A+"! --");
      String Rs=fct.toString();
      int cnt[]=new int[10];
      for(int i=0;i<Rs.length();i++){
        cnt[Rs.charAt(i)-'0']++;
      }
      for(int i=0;i<10;i++){
        if(i==0||i==5) System.out.printf("   ").print("");
        else System.out.printf("    ").print("");
        System.out.printf("(%d)%5d",i,cnt[i]).print("");
        if(i==4 || i==9) System.out.println();
      }
    }
  }
}
