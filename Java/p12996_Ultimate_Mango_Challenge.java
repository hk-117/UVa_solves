import java.util.Scanner;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int cas = sc.nextInt();
    for(int cs=1; cs<=cas; cs++){
      int N = sc.nextInt();
      int L = sc.nextInt();
      int plates[] = new int[N];
      int limits[] = new int[N];
      int plateTotal = 0;
      for(int i=0;i<N;i++){
        plates[i] = sc.nextInt();
        plateTotal += plates[i];
      }
      for(int i=0;i<N;i++){
        limits[i] = sc.nextInt();
      }
      System.out.print("Case " + cs + ": ");
      if(plateTotal>L){
        System.out.println("No");
      }else{
        boolean pass = true;
        for(int i=0; i<N; i++){
          if(plates[i]>limits[i]){
            pass = false;
            break;
          }
        }
        if(pass){
          System.out.println("Yes");
        }else{
          System.out.println("No");
        }
      }
    }
    sc.close();
  }
}
