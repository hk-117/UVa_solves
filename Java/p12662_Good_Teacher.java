import java.util.Scanner;

class Main{
  public static void main(String args[]){
    
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String names[] = new String[n];

    for(int i=0;i<n;i++){
      names[i] = sc.next();
    }

    int leftPos[] = new int[n];
    int rightPos[] = new int[n];

    int posVal = -1;

    for(int i=0;i<n;i++){
      if(names[i].equals("?")){
        if(posVal == -1){
          leftPos[i] = posVal;
        }else{
          posVal++;
          leftPos[i] = posVal;
        }
      }else{
        posVal = 0;
        leftPos[i] = posVal;
      }
    }

    posVal = -1;
    for(int i=n-1;i>=0;i--){
      if(names[i].equals("?")){
        if(posVal == -1){
          rightPos[i] = posVal;
        }else{
          posVal++;
          rightPos[i] = posVal;
        }
      }else{
        posVal = 0;
        rightPos[i] = posVal;
      }
    }

    int q = sc.nextInt();
    for(int i=0;i<q;i++){
      
      int query = sc.nextInt();
      int leftVal = leftPos[query-1];
      int rightVal = rightPos[query-1];

      if(leftVal == -1){
        printLeftOf(names, rightVal, query-1);
      }else{
        if(rightVal == -1){
          printRightOf(names, leftVal, query-1);
        }else{
          if(leftVal < rightVal){
            printRightOf(names, leftVal, query-1);
          } else if(leftVal > rightVal){
            printLeftOf(names, rightVal, query-1);
          } else {
            if(leftVal==0 && rightVal==0){
              System.out.println(names[query-1]);
            } else {
              printMiddleOf(names, leftVal, query-1);
            }
          }
        }
      }

    }

    sc.close();
  }

  public static void printRightOf(String names[],int times, int currentPos){
    for(int i=1;i<=times;i++){
      System.out.print("right of ");
      currentPos--;
    }
    System.out.println(names[currentPos]);
  }

  public static void printLeftOf(String names[],int times, int currentPos){
    for(int i=1;i<=times;i++){
      System.out.print("left of ");
      currentPos++;
    }
    System.out.println(names[currentPos]);
  }

  public static void printMiddleOf(String names[], int adjustVal, int currentPos){
    int lPos = currentPos-adjustVal;
    int rPos = currentPos+adjustVal;
    System.out.println("middle of " + names[lPos] + " and " + names[rPos]);
  }
}
