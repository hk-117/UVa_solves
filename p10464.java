import java.util.Scanner;
import java.math.BigDecimal;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int N=sc.nextInt();
    while(N-- > 0){
      BigDecimal a=sc.nextBigDecimal();
      BigDecimal b=sc.nextBigDecimal();
      String res= a.add(b).stripTrailingZeros().toPlainString();
      if(!anyDot(res)){
        System.out.println(res+".0");
      }
      else{
        System.out.println(res);
      }
    }
  }
  public static boolean anyDot(String st){
    for(int i=st.length()-1;i>=0;i--){
      if(st.charAt(i) == '.')
        return true;
    }
    return false;
  }
}
