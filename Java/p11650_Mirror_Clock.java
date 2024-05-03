import java.util.Scanner;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int H,M;
        String inp;
        while(t-- > 0){
            inp = sc.next();
            StringTokenizer st = new StringTokenizer(inp, ":");
            H = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            H = (H==12? 0 : H);
            M = (M==0? 60 : M);
            H = 11 - H;
            M = 60 - M;
            if(M==0)
                H += 1;
            if(H==0)
                H = 12;
            System.out.print(H<10?"0"+H : H);
            System.out.print(":");
            System.out.println(M<10?"0"+M : M);
        }
        sc.close();
    }
}
