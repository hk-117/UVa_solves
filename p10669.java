import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger Base= new BigInteger("3");
    while(true){
      long N=sc.nextLong();
      if(N==0) break;
      N=N-1;
      long pos;
      System.out.print("{");
      while(N!=0){
        long Id = N & (-N);
        pos=0;
        while(Id != 0){
          pos=pos+1;
          Id=Id/2;
        }
        System.out.print(" "+Base.pow((int)pos-1));
        N=N & (N-1);
        if(N != 0)
          System.out.print(",");
      }
      System.out.println(" }");
    }
  }
}
