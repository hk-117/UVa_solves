import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String inline;
    boolean first=true;
    while(sc.hasNext()){
      inline = sc.nextLine();
      for(int i=0;i<inline.length();i++){
        if(inline.charAt(i) == '"'){
          if(first){
            System.out.print("``");
            first = false;
          }else{
            System.out.print("''");
            first = true;
          }
        }else{
          System.out.print(inline.charAt(i));
        }
      }
      System.out.println("");
    }
  }
}
