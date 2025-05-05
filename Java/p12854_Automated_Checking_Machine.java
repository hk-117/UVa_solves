import java.util.Scanner;

class Main{
  public static void main(String args[]){

    Scanner sc = new Scanner(System.in);

    while(sc.hasNext()){

      int cnUp[] = new int[5];
      int cnDown[] = new int[5];

      for(int i=0;i<5;i++){
        cnUp[i] = sc.nextInt();
      }

      for(int i=0;i<5;i++){
        cnDown[i] = sc.nextInt();
      }

      boolean compatible = true;
      for(int i=0;i<5;i++){
        if(cnUp[i] == cnDown[i]){
          compatible = false;
          break;
        }
      }

      if(compatible){
        System.out.println("Y");
      }else{
        System.out.println("N");
      }

    }
    sc.close();
  }
}
