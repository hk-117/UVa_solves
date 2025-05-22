import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    try{
      while(true){
        String input = br.readLine();
        if(input == null){
          break;
        }
        int n = Integer.parseInt(input.split(" ")[0]);
        int m = Integer.parseInt(input.split(" ")[1]);
        int total = 0;
        for(int i=0;i<n;i++){
          boolean scored = true;
          String goals[] = br.readLine().split(" ");
          for(int j=0;j<m;j++){
            if(goals[j].trim().equals("0")){
              scored = false;
            }
          }
          if(scored){
            total++;
          }
        }
        bw.write(Integer.toString(total) + "\n");
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
}