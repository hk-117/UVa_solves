import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    BigInteger Y;
    int bs=2148;
    boolean nl=false;
    while(true){
      Y=sc.nextBigInteger();
      if(Y.equals(BigInteger.ZERO)) break;
      if(nl){
        System.out.println();
      }
      else{
        nl=true;
      }
      System.out.println(Y);
      if(Y.compareTo(BigInteger.valueOf(2148))<0){
        System.out.println("No ghost will come in this year");
        continue;
      }
      BigInteger diff = Y.subtract(BigInteger.valueOf(bs));
      boolean any=false;
      if(diff.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Tanveer Ahsan!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(5)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Shahriar Manzoor!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(7)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Adrian Kugel!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Anton Maydell!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(15)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Derek Kisman!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(20)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Rezaul Alam Chowdhury!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(28)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Jimmy Mardell!!!");
        any=true;
      }
      if(diff.mod(BigInteger.valueOf(36)).equals(BigInteger.ZERO)){
        System.out.println("Ghost of Monirul Hasan!!!");
        any=true;
      }
      if(isLeap(Y)){
        System.out.println("Ghost of K. M. Iftekhar!!!");
        any=true;
      }
      if(!any){
        System.out.println("No ghost will come in this year");
      }
    }
  }
  public static boolean isLeap(BigInteger Y){
      if(Y.mod(BigInteger.valueOf(400)).equals(BigInteger.ZERO)){
        return true;
      }
      else if(Y.mod(BigInteger.valueOf(100)).equals(BigInteger.ZERO)){
        return false;
      }  
      else if(Y.mod(BigInteger.valueOf(4)).equals(BigInteger.ZERO)){
        return true;
      }
      else{
        return false;
      }
  }
}
