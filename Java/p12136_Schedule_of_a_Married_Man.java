import java.util.Scanner;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        String input;
        int times[] = new int[4];
        int tmp;
        StringTokenizer strtok;
        for(int i=1;i<=t;i++){
            for(int j=0;j<4;j++){
                input = sc.next();
                strtok = new StringTokenizer(input,":");
                tmp = Integer.parseInt(strtok.nextToken()) * 60;
                tmp += Integer.parseInt(strtok.nextToken());
                times[j] = tmp;
            }
            if((times[0]>=times[2] && times[0]<=times[3])||(times[2]>=times[0] && times[2]<=times[1])){
                System.out.println("Case "+i+": Mrs Meeting");
            }else{
                System.out.println("Case "+i+": Hits Meeting");
            }
        }
        sc.close();
    }
}
