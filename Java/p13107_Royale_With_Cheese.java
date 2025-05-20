import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    try{
      while(true){
        String houseStr = br.readLine();
        if(houseStr == null){
          break;
        }
        int hash[] = new int[26];
        int count = 0;
        for(int i=0;i<houseStr.length();i++){
          char c = houseStr.charAt(i);
          if(hash[c-'a'] == 0){
            count++;
            hash[c-'a'] = count;
            printNo(count, bw);
          }else{
            printNo(hash[c-'a'], bw);
          }
        }
        bw.write('\n');
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }

  public static void printNo(int value, BufferedWriter bw) throws IOException{
    String out = Integer.toString(value);
    for(int i=0;i<out.length();i++){
      char c = out.charAt(i);
      switch (c) {
        case '2':
          bw.write('5');
          break;
        case '5':
          bw.write('2');
          break;
        case '6':
          bw.write('9');
          break;
        case '9':
          bw.write('6');
          break;
        default:
          bw.write(c);
      }
    }
  }
}