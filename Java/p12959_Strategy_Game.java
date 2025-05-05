import java.io.*;

class Main{
  public static void main(String args[]){

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line;

    try {
      while(true){
        line = br.readLine();
        if(line==null || line==""){
          break;
        }
        int J = Integer.parseInt(line.split(" ")[0]);
        int R = Integer.parseInt(line.split(" ")[1]);

        String pointString = br.readLine();
        String pointInput[] = pointString.split(" ");
        int k = 0;

        int points[] = new int[J];
        int best = 0;
        int bestPos = 0;

        for(int i=1; i<=R; i++){
          for(int j=0;j<J;j++){
            points[j] += Integer.parseInt(pointInput[k++]);
            if(points[j] >= best){
              best = points[j];
              bestPos = j;
            }
          }
        }

        System.out.println(bestPos+1);

      }
    } catch (Exception e) {
      System.out.print("");
    }
  }
}
