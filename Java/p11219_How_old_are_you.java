import java.util.Scanner;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        class AgeCal{
            int year,month,day;
            public AgeCal(int year,int month, int day){
                this.year = year;
                this.month = month;
                this.day = day;
            }
            public int getYearDiff(AgeCal t){
                int diff = this.year - t.year;
                if(month < t.month || (month==t.month && day<t.day)){
                    diff--;
                }
                return diff;
            }
        }

        int t = sc.nextInt();
        String inp;
        AgeCal current, dob;
        StringTokenizer st;
        int year,month,day;
        for(int i=1;i<=t;i++){
            inp = sc.next();
            st = new StringTokenizer(inp,"/");
            day = Integer.parseInt(st.nextToken());
            month = Integer.parseInt(st.nextToken());
            year = Integer.parseInt(st.nextToken());
            current = new AgeCal(year,month,day);
            inp = sc.next();
            st = new StringTokenizer(inp,"/");
            day = Integer.parseInt(st.nextToken());
            month = Integer.parseInt(st.nextToken());
            year = Integer.parseInt(st.nextToken());
            dob = new AgeCal(year,month,day);
            System.out.print("Case #" + i + ": ");
            int yearDiff = current.getYearDiff(dob);
            if(yearDiff<0){
                System.out.println("Invalid birth date");
            }else if(yearDiff>130){
                System.out.println("Check birth date");
            }else {
                System.out.println(yearDiff);
            }
        }
        sc.close();
    }
}
