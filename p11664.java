import java.util.Scanner;
import java.math.BigInteger;
class Main{
  public boolean W[][];
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int n,x,y;
    BigInteger c;
    int px[]={0,0,-1,1},py[]={1,-1,0,0};
    while(true){
      n=sc.nextInt();
      c=sc.nextBigInteger();
      x=sc.nextInt();
      y=sc.nextInt();
      if(n==0 && c.equals(BigInteger.ZERO) && x==0 && y==0) break;
      Main M= new Main();
      M.initWorld(n,n);
      String rep= c.toString(2);
      if(rep.length()<n*n){
        StringBuilder st=new StringBuilder(rep);
        for(int i=1;i<=(n*n)-rep.length();i++){
          st.insert(0,'0');
        }
        rep=st.toString();
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          M.setRegion(n-1-i,j,rep.charAt(n*i+j));
        }
      }
      boolean possible;
      int dir=2;
      int tmp= n-y;
      y=x-1;
      x=tmp;
      //System.out.println("Source: "+x+","+y);
      while(true){
        if(!chkMove(x,y,n)){
          possible=false;
          break;
        }
        else{
          if(x==0 && y==n-1){
            possible=true;
            break;
          }
        }
        if(M.testRegion(x,y)){
          if(dir==2){
            dir=0;
            M.setRegion(x,y,'0');
            x= x+px[dir];
            y= y+py[dir];
          }
          else if(dir==3){
            dir=1;
            M.setRegion(x,y,'0');
            x= x+px[dir];
            y= y+py[dir];
          }
          else if(dir==0){
            dir=3;
            M.setRegion(x,y,'0');
            x= x+px[dir];
            y= y+py[dir];
          }
          else{
            dir=2;
            M.setRegion(x,y,'0');
            x= x+px[dir];
            y= y+py[dir];
          }
        }
        else{
          if(dir==2){
            dir=1;
            M.setRegion(x,y,'1');
            x= x+px[dir];
            y= y+py[dir];
          }
          else if(dir==3){
            dir=0;
            M.setRegion(x,y,'1');
            x= x+px[dir];
            y= y+py[dir];
          }
          else if(dir==0){
            dir=2;
            M.setRegion(x,y,'1');
            x= x+px[dir];
            y= y+py[dir];
          }
          else{
            dir=3;
            M.setRegion(x,y,'1');
            x= x+px[dir];
            y= y+py[dir];
          }
        }
      }
      if(possible)
        System.out.println("Yes");
      else{
        System.out.println("Kaputt!");
      }
    }
  }
  public static boolean chkMove(int x,int y,int n){
    //System.out.println("Moved to:("+x+","+y+")");
    if(x<0 || y<0 || x>=n || y>=n)
      return false;
    return true;
  }
  public void initWorld(int x,int y){
    W= new boolean[x][y];
  }
  public void setRegion(int x,int y,char val){
    if(val=='0')
      W[x][y]=false;
    else
      W[x][y]=true;
  }
  public boolean testRegion(int x,int y){
    return W[x][y];
  }
}
