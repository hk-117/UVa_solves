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
        int n = Integer.parseInt(br.readLine());
        if(n == 0){
          break;
        }
        String plain = br.readLine();
        n %= 26;
        if(n<0){
          n = 26 + n;
        }
        for(int i=0;i<plain.length();i++){
          if(Character.isAlphabetic(plain.charAt(i))){
            int shifted = 0;
            if(Character.isUpperCase(plain.charAt(i))){
              shifted = (((plain.charAt(i) - 'A') + n) % 26);
              bw.write('A' + shifted);
            }else{
              shifted = (((plain.charAt(i) - 'a') + n) % 26);
              bw.write('a' + shifted);
            }
          }else{
            bw.write(plain.charAt(i));
          }
        }
        bw.write('\n');
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
}