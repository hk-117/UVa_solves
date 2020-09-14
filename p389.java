import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    while(sc.hasNext()){
      String nm= sc.next();
      BigInteger Num= new BigInteger(nm,sc.nextInt());
      int bs=sc.nextInt();
      String cnv= Num.toString(bs).toUpperCase();
      if(cnv.length() > 7){
        System.out.printf("%7s","ERROR").println();
      }
      else{
        System.out.printf("%7s",cnv).println();
      }
    }
  }
}
