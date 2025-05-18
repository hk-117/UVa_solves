import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    try{
      while(true){

        String inp = br.readLine();
        if(inp == null || inp==""){
          break;
        }

        String strParts[] = inp.split(" ");
        List<Integer> parts = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        Map<Integer,Integer> mp = new TreeMap<>();

        for(int i=0;i<strParts.length;i++){
          if(!strParts[i].equals("")){
            parts.add(Integer.parseInt(strParts[i]));
          }
        }
        
        for(int i=0;i<parts.size();i++){
          int current = parts.get(i);
          if(!st.empty()){
            int peek = parts.get(st.peek());
            if(peek == -current){
              st.pop();
              if(!st.empty()){
                int npeek = st.peek();
                if(mp.containsKey(npeek)){
                  mp.put(npeek,mp.get(npeek)+(current));
                }else{
                  mp.put(npeek,current);
                }
              }
            }else{
              st.push(i);
            }
          }else{
            st.push(i);
          }
        }
        if(!st.empty()){
          bw.write(":-( Try again.\n");
        }else{
          if(determineMat(mp,parts)){
            bw.write(":-) Matrioshka!\n");
          }else{
            bw.write(":-( Try again.\n");
          }
        }
      }
      bw.flush();
    } catch (Exception e){
      e.printStackTrace();
    }
  }

  public static boolean determineMat(Map<Integer,Integer> mp, List<Integer> parts){
    Set<Map.Entry<Integer,Integer>> set = mp.entrySet();
    for(Map.Entry<Integer,Integer> item : set){
      if(item.getValue() >= Math.abs(parts.get(item.getKey()))){
        return false;
      }
    }
    return true;
  }
}