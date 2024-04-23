import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap<String,Integer> monthMap = new HashMap<String,Integer>();   
        String months[] = {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
        };
        for(int i=0;i<12;i++) {
            monthMap.put(months[i],i);
        }
        int t = sc.nextInt();
        for(int cs = 1; cs <= t; cs++){
            String inp = sc.next();
            int days = sc.nextInt();
            StringTokenizer tok = new StringTokenizer(inp,"-");
            GregorianCalendar cal = new GregorianCalendar(
                        Integer.parseInt(tok.nextToken()),
                        monthMap.get(tok.nextToken()),
                        Integer.parseInt(tok.nextToken())
                    );
            cal.add(Calendar.DATE,days);
            System.out.print("Case "+ cs + ": ");
            System.out.print(cal.get(Calendar.YEAR)+"-");
            System.out.print(months[cal.get(Calendar.MONTH)]+"-");
            int day = cal.get(Calendar.DATE);
            System.out.println(day>9 ? day : ("0" + day));
        }
    }
}
