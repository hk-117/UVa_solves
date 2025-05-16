import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    try{
      int t = Integer.parseInt(br.readLine());
      for(int cs = 1; cs <= t; cs++){
        bw.write("Case #" + cs + ": ");
        int original[][] = new int[2][2];
        int given[][] = new int[2][2];
        for(int i=0;i<2;i++){
          String inp = br.readLine();
          original[i][0] = Integer.parseInt(inp.split(" ")[0]);
          original[i][1] = Integer.parseInt(inp.split(" ")[1]);
        }
        for(int i=0;i<2;i++){
          String inp = br.readLine();
          given[i][0] = Integer.parseInt(inp.split(" ")[0]);
          given[i][1] = Integer.parseInt(inp.split(" ")[1]);
        }
        int count = 0;
        do{
          if(isPossible(original, given)){
            bw.write("POSSIBLE\n");
            break;
          }else{
            rotatePlan(given);
            count++;
          }
        }while(count<=4);
        if(count>4){
          bw.write("IMPOSSIBLE\n");
        }
        br.readLine();
      }
      bw.flush();
    } catch (Exception e){
      System.out.print("");
    }
  }

  public static boolean isPossible(int original[][], int rotated[][]){
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        if(original[i][j] != rotated[i][j]){
          return false;
        }
      }
    }
    return true;
  }

  public static void rotatePlan(int given[][]){
    int tmp = given[0][0];
    given[0][0] = given[0][1];
    given[0][1] = given[1][1];
    given[1][1] = given[1][0];
    given[1][0] = tmp;
  }

}