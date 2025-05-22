import java.util.Scanner;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNext()){
      int N = sc.nextInt();
      int M = sc.nextInt();
      int total = 0;
      int dae = 0;
      for(int i=1;i<=M;i++){
        int B = sc.nextInt();
        int tmpDae = sc.nextInt();
        int others = 0;
        for(int j=1;j<N;j++){
          others += sc.nextInt();
        }
        if(tmpDae + others <= B){
          dae += tmpDae;
        }
        total += determineMax(B, others);
      }
      System.out.println(total - dae);
    }
    sc.close();
  }

  public static int determineMax(int B, int Others){
    if(Others > B){
      return 0;
    }
    int labels[] = {10000,1000,100,10,1};
    for(int i=0;i<5;i++){
      if(Others + labels[i] <= B){
        return labels[i];
      }
    }
    return 0;
  }
}