import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger N=BigInteger.ONE;
    int T[]=new int[1001];
    T[0]=1;
    T[1]=1;
    for(int i=2;i<=1000;i++){
      N=N.multiply(BigInteger.valueOf(i));
      T[i]=calcSum(N.toString());
    }
    while(sc.hasNext()){
      int pos=sc.nextInt();
      System.out.println(T[pos]);
    }
  }
  public static int calcSum(String NM){
    int sm=0;
    for(int i=0;i<NM.length();i++){
      sm += NM.charAt(i)-'0';
    }
    return sm;
  }
}
