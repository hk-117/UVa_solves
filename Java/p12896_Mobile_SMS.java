import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String lookTable[] = {" ", ".,?\"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    try{
      int T = Integer.parseInt(br.readLine());
      while(T-- > 0){
        int L = Integer.parseInt(br.readLine());
        String message[] = br.readLine().split(" ");
        String count[] = br.readLine().split(" ");
        for(int i=0;i<L;i++){
          int button = Integer.parseInt(message[i]);
          int times = Integer.parseInt(count[i])-1;
          bw.write(lookTable[button].charAt(times));
        }
        bw.write('\n');
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
}