import java.io.*;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    long N;
    try{
      while((N=Long.parseLong(br.readLine())) != 0){
        long sqrt = (long) Math.sqrt(N);
        if(sqrt * sqrt == N){
          bw.write("yes\n");
        }else{
          bw.write("no\n");
        }
      }
      bw.flush();
    } catch (Exception e){
      System.out.println("");
    }
  }
}
