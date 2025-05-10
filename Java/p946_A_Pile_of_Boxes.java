/*
 * Borrowed the Idea ***
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.List;

class Main{
  public static void main(String args[]){
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    int N;
    String input;
    try{
      while(true){
        
        input = br.readLine();
        if(input == null || input==""){
          break;
        }

        N = Integer.parseInt(input);

        Cube root = new Cube(Integer.MAX_VALUE);

        for(int i=0;i<N;i++){
          int width = Integer.parseInt(br.readLine());
          Cube nCube = new Cube(width);
          makeStack(root, nCube);         
        }

        int total = 0;
        for(int i=0;i<root.iQb.size();i++){
          total += root.iQb.get(i).W;
        }
        bw.write(total + "\n");
        br.readLine();
      }
      bw.flush();
    } catch (Exception e){
      System.out.println("");
    }
  }

  public static boolean makeStack(Cube root, Cube leaf){
    for(int i=0;i<root.iQb.size();i++){
      if(makeStack(root.iQb.get(i), leaf)){
        return true;
      }
    }
    if(leaf.H > root.H){
      return false;
    }
    root.H -= leaf.H;
    root.iQb.add(leaf);
    return true;
  }

}

class Cube{

  public int W;
  public int H;
  public List<Cube> iQb;

  public Cube(int W){
    this.W = W;
    this.H = W;
    this.iQb = new LinkedList<>();
  }

}
