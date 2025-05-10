import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    int t = 0;
    String input;
    try{
      while(true){
        
        input = br.readLine();
        int N = Integer.parseInt(input);
        
        if(input == null || input=="" || N == 0){
          break;
        }

        t++;
        bw.write("Triangle #" + t + "\n");

        int triangles[][] = new int[N][2*N-1];
        for(int i=0;i<N;i++){
          input = br.readLine();
          for(int j=0;j<input.length();j++){
            if(input.charAt(j) == '#'){
              triangles[i][j] = -1;
            }else if(input.charAt(j) == '-'){
              triangles[i][j] = 1;
            }
          }
        }

        int maxArea = 0;
        int area;
        for(int i=0;i<N;i++){
          for(int j=i; j<(2*N-1-i);j++){
            if(triangles[i][j] == 1){
              if((j%2 == 0 && i%2==0) || (j%2 == 1 && i%2==1)){
                area = findUpwardArea(triangles,i,j);
                maxArea = maxArea < area ? area : maxArea;
              }else{
                area = findDownwardArea(triangles,i,j);
                maxArea = maxArea < area ? area : maxArea;
              }
            }
          }
        }
        bw.write("The largest triangle area is " + maxArea + ".\n\n");
        
      }
      bw.flush();
    } catch (Exception e){
      System.out.println("");
    }
  }

  public static int findUpwardArea(int triangles[][],int x, int y){
    int pad = 1;
    int area = 1;
    x--;
    while(x>=0){
      if(hasRequiredTriangles(triangles, x, y-pad, y+pad)){
        area += (2*pad + 1);
      }else{
        break;
      }
      pad++;
      x--;
    }
    return area;
  }

  public static int findDownwardArea(int triangles[][],int x, int y){
    int pad = 1;
    int area = 1;
    x++;
    while(x<triangles.length){
      if(hasRequiredTriangles(triangles, x, y-pad, y+pad)){
        area += (2*pad + 1);
      }else{
        break;
      }
      pad++;
      x++;
    }
    return area;
  }

  public static boolean hasRequiredTriangles(int triangles[][], int x, int start, int end){
    for(int i=start;i<=end;i++){
      if(i<0 || i>=triangles[x].length){
        return false;
      }
      if(triangles[x][i] != 1){
        return false;
      }
    }
    return true;
  }
}