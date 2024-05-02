import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        String days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        while(t-- > 0){
            int M = sc.nextInt();
            int D = sc.nextInt();
            GregorianCalendar gc = new GregorianCalendar(2011,M-1,D);
            System.out.println(days[gc.get(Calendar.DAY_OF_WEEK)-1]);
        }
        sc.close();
    }
}
