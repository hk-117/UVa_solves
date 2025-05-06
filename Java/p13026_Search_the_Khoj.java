import java.io.*;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    try {
      int cas = Integer.parseInt(br.readLine());
      for(int cs=1; cs<=cas; cs++){
        System.out.println("Case " + cs + ":");
        int N = Integer.parseInt(br.readLine());
        String phoneBook[] = new String[N];
        String mmNumber;
        for(int i=0;i<N;i++){
          phoneBook[i] = br.readLine();
        }
        mmNumber = br.readLine();
        for(int i=0;i<N;i++){
          if(isSimilar(mmNumber,phoneBook[i])){
            System.out.println(phoneBook[i]);
          }
        }
      }
    } catch (Exception e) {
      System.out.print("");
    }
  }

  public static boolean isSimilar(String mmNum, String toCheck){
    int diff = 0;
    for(int i=0;i<mmNum.length();i++){
      if(mmNum.charAt(i) != toCheck.charAt(i)){
        diff++;
      }
      if(diff > 1){
        return false;
      }
    }
    return true;
  }

}
