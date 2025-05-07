import java.util.Scanner;

class Main{
  public static void main(String args[]){ 
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cs = 1; cs<=T; cs++){
      String S = sc.next();
      int spaceCount = 0;
      for(int i=0; i<S.length(); i++){
        if(S.charAt(i)=='-'){
          if(isValidSpace(S, i)){
            spaceCount++;
          }
        }
      }
      System.out.println("Case " + cs + ": " + spaceCount);
    }
    sc.close();
  }

  public static boolean isValidSpace(String S, int pos){
    int len = S.length();
    if(pos>0 && S.charAt(pos-1)=='S'){
      return false;
    }
    if((pos+1 < len) && (S.charAt(pos+1)=='S' || S.charAt(pos+1)=='B')){
      return false;
    }
    if((pos+2 < len) && (S.charAt(pos+2)=='B')){
      return false;
    }
    return true;
  }
}
