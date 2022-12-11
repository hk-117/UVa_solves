import java.util.Scanner;
import java.math.BigInteger;

class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    String Inp;
    BigInteger N=new BigInteger("0"),Bs=new BigInteger("26");
    while(true){
      Inp=sc.nextLine();
      if(Inp.charAt(0)=='*') break;
      if(Inp.charAt(0)>='0' && Inp.charAt(0)<='9'){
        N=new BigInteger(Inp);
        StringBuilder sb = new StringBuilder();
        do{
          sb.append((char)('a' +
          N.subtract(BigInteger.ONE).mod(Bs).intValue()));
          N = N.subtract(BigInteger.ONE).divide(Bs);
        }while(N.compareTo(BigInteger.ZERO) != 0);
        sb.reverse();
        System.out.printf("%-22s",sb).print("");
        int len=Inp.length();
        for(int i=1;i<=len;i++){
            if((len-i)%3==0 && (i!=0 && i!=Inp.length())){
              System.out.print(Inp.charAt(i-1)+",");
            }
            else{
              System.out.print(Inp.charAt(i-1));
            }
        }
        System.out.println();
      }
      else{
        int sz=Inp.length();
        N=new BigInteger("0");
        for(int i=sz-1;i>=0;i--){
          BigInteger tmp = Bs.pow(sz-i-1).multiply(BigInteger.valueOf(Inp.charAt(i)-'a'+1));
          N=N.add(tmp);
        }
        System.out.printf("%-22s",Inp).print("");
        Inp=N.toString();
        int len=Inp.length();
        for(int i=1;i<=len;i++){
            if((len-i)%3==0 && (i!=0 && i!=Inp.length())){
              System.out.print(Inp.charAt(i-1)+",");
            }
            else{
              System.out.print(Inp.charAt(i-1));
            }
        }
        System.out.println();
      }
    }
  }
}
