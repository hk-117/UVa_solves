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
      for(int cs=1;cs<=t;cs++){
        bw.write("Case " + cs + ": ");
        int n = Integer.parseInt(br.readLine());
        int continuous = 0;
        int survived = 0;
        char results[] = new char[n];
        for(int i=0;i<n;i++){
          String c = br.readLine();
          results[i] = c.charAt(0);
        }
        for(int i=0;i<n;i++){
          if(results[i] != 'W'){
            continuous++;
            if(continuous==3){
              survived++;
              break;
            }else{
              survived++;
            }
          }else{
            continuous = 0;
            survived++;
          }
        }
        if(continuous == 3){
          bw.write(Integer.toString(survived) + "\n");
        }else{
          if(survived == n){
            bw.write("Yay! Mighty Rafa persists!\n");
          }else{
            bw.write(Integer.toString(survived) + "\n");
          }
        }
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
}