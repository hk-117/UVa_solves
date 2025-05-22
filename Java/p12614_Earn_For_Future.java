import java.util.Scanner;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cs=1; cs<=T; cs++){
      int N = sc.nextInt();
      int max = Integer.MIN_VALUE;
      for(int i=1; i<=N; i++){
        int tmp = sc.nextInt();
        if(max < tmp){
          max = tmp;
        }
      }
      System.out.println("Case " + cs + ": " + max);
    }
    sc.close();
  }
}