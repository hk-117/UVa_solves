import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static BigInteger Tbl[]=new BigInteger[82];
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    Tbl[0]=new BigInteger("0");
    Tbl[1]=new BigInteger("1");
    Tbl[2]=new BigInteger("2");
    for(int i=3;i<=81;i++){
      Tbl[i]=BigInteger.ZERO;
    }
    while(true){
      int G=sc.nextInt();
      if(G==0) break;
      System.out.println(findGen(G));
    }
  }
  public static BigInteger findGen(int G){
    if(G<=0) return Tbl[0];
    if(G==1) return Tbl[1];
    if(G==2) return Tbl[2];
    if(!Tbl[G].equals(BigInteger.ZERO)) return Tbl[G];
    BigInteger a= findGen(G-1);
    BigInteger b=findGen(G-2);
    Tbl[G]=a.add(b);
    return Tbl[G];
  }
}
