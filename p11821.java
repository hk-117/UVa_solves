import java.util.Scanner;
import java.math.BigDecimal;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    while(N-- > 0){
      BigDecimal sum=BigDecimal.ZERO;
      BigDecimal a;
      while(true){
        a=sc.nextBigDecimal();
        if(a.equals(BigDecimal.ZERO)) break;
        sum=sum.add(a);
      }
      System.out.println(sum.stripTrailingZeros().toPlainString());
    }
  }
}
