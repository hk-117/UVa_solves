import java.util.Scanner;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int total = 0;
    while(n-- > 0){
      double l = sc.nextDouble();
      double w = sc.nextDouble();
      double d = sc.nextDouble();
      double wt = sc.nextDouble();
      if(checkAllowed(l, w, d, wt)){
        System.out.println("1");
        total++;
      }else{
        System.out.println("0");
      }
    }
    System.out.println(total);
    sc.close();
  }

  public static boolean checkAllowed(double l, double w, double d, double wt){
    double total = l + w + d;
    if((total <= 125.00) && (wt<=7.00)){
      return true;
    }else if(l > 56.00){
      return false;
    } else if(w > 45.00){
      return false;
    } else if(d > 25.00){
      return false;
    } else if(wt>7.00){
      return false;
    }
    return true;
  }
}