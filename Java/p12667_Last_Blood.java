import java.util.*;

class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    
    int n = sc.nextInt();
    int t = sc.nextInt();
    int m = sc.nextInt();

    boolean TP[][] = new boolean[t][n];
    int TI[] = new int[n];
    int TM[] = new int[n];

    for(int i=0;i<m;i++){
      int time = sc.nextInt();
      int team = sc.nextInt();
      String problem = sc.next();
      String ver = sc.next();
      char pb = problem.charAt(0);
      if(ver.equals("Yes")){
        if(TP[team-1][pb-'A'] == false){
          TP[team-1][pb-'A'] = true;
          TI[pb-'A'] = time;
          TM[pb-'A'] = team;
        }
      }
    }

    for(int i=0;i<n;i++){
      char tmp = (char) ('A' + i);
      if(TI[i] == 0 && TM[i] == 0){
        System.out.println(tmp + " - -");
      }else{
        System.out.println(tmp + " " + TI[i] + " " + TM[i]);
      }
    }

    sc.close();
  }
}