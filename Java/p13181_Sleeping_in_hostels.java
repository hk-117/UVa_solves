import java.io.*;

class Main{
  public static void main(String args[]){
    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    try{
      String beds;
      while ( (beds=sc.readLine()) != null ) {
        int xCount = 0;
        int distance=0;
        int tmpGap = 0;
        for(int i=0;i<beds.length();i++){
          if(beds.charAt(i) == 'X'){
            xCount++;
            if(xCount==1){
              distance = tmpGap-1;
            }else{
              if((tmpGap-1)/2 > distance){
                distance = (tmpGap-1)/2;
              }
            }
            tmpGap = 0;
          } else {
            tmpGap++;
            if(beds.length()==i+1){
              distance = (tmpGap-1)> distance ? (tmpGap-1) : distance;
            }
          }
        }
        System.out.println(distance);
      }
    } catch (Exception e){
      System.out.print("");
    }
  }
}
