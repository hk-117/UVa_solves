import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    try{
      while(true){
        String cipher = br.readLine();
        if(cipher==null){
          break;
        }
        String plain = br.readLine();
        Map<Character,Integer> cipherCount = new TreeMap<>();
        Map<Character,Integer> plainCount = new TreeMap<>();
        for(int i=0;i<plain.length();i++){
          
          if(cipherCount.containsKey(cipher.charAt(i))){
            cipherCount.put(cipher.charAt(i), cipherCount.get(cipher.charAt(i))+1);
          }else{
            cipherCount.put(cipher.charAt(i), 1);
          }

          if(plainCount.containsKey(plain.charAt(i))){
            plainCount.put(plain.charAt(i), plainCount.get(plain.charAt(i))+1);
          }else{
            plainCount.put(plain.charAt(i), 1);
          }

        }
        if(cipherCount.size() != plainCount.size()){
          bw.write("NO\n");
        }else{
          int ciCountArr[] = new int[cipherCount.size()];
          int plCountArr[] = new int[plainCount.size()];
          int i = 0;
          for(Map.Entry<Character,Integer> item : cipherCount.entrySet()){
            ciCountArr[i++] = item.getValue();
          }
          i = 0;
          for(Map.Entry<Character,Integer> item : plainCount.entrySet()){
            plCountArr[i++] = item.getValue();
          }
          Arrays.sort(ciCountArr);
          Arrays.sort(plCountArr);
          boolean possible = true;
          for(i=0;i<ciCountArr.length;i++){
            if(ciCountArr[i] != plCountArr[i]){
              possible = false;
              break;
            }
          }
          bw.write(possible ? "YES\n" : "NO\n");
        }
        
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
      System.out.println("");
    }
  }
}