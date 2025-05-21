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
        int h = Integer.parseInt(input.split(" ")[0]);
        int w = Integer.parseInt(input.split(" ")[1]);
        double area = 0.0;
        for(int i=0;i<h;i++){
          String row = br.readLine();
          boolean guard = false;
          for(int j=0;j<w;j++){
            if(row.charAt(j) == '.'){
              if(guard){
                area++;
              }
            }else if(row.charAt(j) == '/'){
              area += 0.5;
              guard = !guard;
            }else{
              area += 0.5;
              guard = !guard;
            }
          }
        }
        bw.write(String.format("%.0f\n", area));
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
}