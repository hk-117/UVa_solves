import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    String table[][] = {
      {".*..",".*..",".*..",".*..",".*.."},
      {"***.","..*.","***.","*...","***."},
      {"***.","..*.","***.","..*.","***."}
    };
    try{
      int n = Integer.parseInt(br.readLine());
      String characters[] = new String[5];
      for(int i=0;i<5;i++){
        characters[i] = br.readLine();
      }
      for(int i=0;i<4 * n;i+=4){
        String nwChar[] = new String[5];
        for(int j=0;j<5;j++){
          String sub = characters[j].substring(i,i+4);
          nwChar[j] = sub;
        }
        for(int j=0;j<3;j++){
          if(determineCharacter(nwChar, table[j], bw)){
            bw.write(Integer.toString(j+1));
            break;
          }
        }
      }
      bw.write("\n");
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }

  public static boolean determineCharacter(String sub[], String table[], BufferedWriter bw) throws IOException{
    for(int i=0;i<5;i++){
      if(!sub[i].equals(table[i])){
        return false;
      }
    }
    return true;
  }
}