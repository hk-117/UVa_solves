import java.util.Scanner;
import java.math.BigDecimal;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigDecimal f,ans;
    int b;
    double a;
    while(sc.hasNext()){
      a=sc.nextDouble();
      b=sc.nextInt();
      f=BigDecimal.valueOf(a);
      ans= f.pow(b);
      String st= ans.toPlainString();
      if(st.charAt(0)=='0') st = st.substring(1);
      System.out.println(st);
    }
  }
}
