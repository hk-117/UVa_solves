import java.util.Scanner;
import java.math.BigInteger;
class Main{
  String Dgts="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  int digitVal[];
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    String inp;
    Main Obj= new Main();
    Obj.digitVal=new int[150];
    Obj.makeMap();
    while(sc.hasNext()){
      inp=sc.next();
      String N="";
      int mx=-1;
      for(int i=0;i<inp.length();i++){
        if((inp.charAt(i)>='0' && inp.charAt(i)<='9') || (inp.charAt(i)>='A' && inp.charAt(i)<='Z') || (inp.charAt(i)>='a' && inp.charAt(i)<='z')){
          N+=inp.charAt(i);
          if(mx< Obj.digitVal[inp.charAt(i)]){
            mx= Obj.digitVal[inp.charAt(i)];
          }
        }
      }
      if(mx <1) mx=1;
      boolean found=false;
      int ans=0;
      for(int bs=mx+1;bs>=2 && bs<=62 && !found;bs++){
        BigInteger nm= Obj.convertNum(N,bs);
        if(nm.mod(BigInteger.valueOf(bs-1)).equals(BigInteger.ZERO)){
          found=true;
          ans=bs;
        }
      }
      if(found){
        System.out.println(ans);
      }
      else{
        System.out.println("such number is impossible!");
      }
    }
  }
  void makeMap(){
    for(int i=0;i<62;i++){
      digitVal[(int)Dgts.charAt(i)]=i;
    }
  }
  BigInteger convertNum(String N,int bs){
    BigInteger res=BigInteger.ZERO,Base=BigInteger.valueOf(bs);
    for(int i=N.length()-1;i>=0;i--){
      BigInteger dval= BigInteger.valueOf(digitVal[N.charAt(i)]);
      res= res.add(dval.multiply(Base.pow(N.length()-i-1)));
    }
    return res;
  }
}
