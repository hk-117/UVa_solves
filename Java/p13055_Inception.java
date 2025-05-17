import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    try{
      int n = Integer.parseInt(br.readLine());
      Stack<String> dreamers = new Stack<>();
      for(int i=1;i<=n;i++){
        String inp = br.readLine();
        String keyword = inp.split(" ")[0];
        if(keyword.equals("Sleep")){
          dreamers.push(inp.split(" ")[1]);
        }else if(keyword.equals("Kick")){
          if(!dreamers.empty()){
            dreamers.pop();
          }
        }else{
          if(dreamers.empty()){
            bw.write("Not in a dream\n");
          }else{
            bw.write(dreamers.peek() + "\n");
          }
        }
      }
      bw.flush();
    } catch (Exception e){
      System.out.print("");
    }
  }
}