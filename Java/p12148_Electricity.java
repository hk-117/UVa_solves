import java.util.*;

public class Main{
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);

        class DayBill{
            public int day;
            public int month;
            public int year;
            public int consumption;
            public void copy(DayBill t){
                this.day = t.day;
                this.month = t.month;
                this.year = t.year;
                this.consumption = t.consumption;
            }
            public void setDate(GregorianCalendar gc){
                this.day = gc.get(Calendar.DATE);
                this.month = gc.get(Calendar.MONTH)+1;
                this.year = gc.get(Calendar.YEAR);
            }
            public boolean equals(DayBill t){
                if(this.day == t.day && this.month==t.month && this.year==t.year){
                    return true;
                }
                return false;
            }
        }

        int t;

        while(true){
            t = sc.nextInt();
            if(t==0){
                break;
            }

            DayBill pB = new DayBill();
            DayBill tB = new DayBill();
            int conCount = 0;
            long totalConsum = 0;
            pB.day = sc.nextInt();
            pB.month = sc.nextInt();
            pB.year = sc.nextInt();
            pB.consumption = sc.nextInt();
            t--;

            while(t-- > 0){
                tB.day = sc.nextInt();
                tB.month = sc.nextInt();
                tB.year = sc.nextInt();
                tB.consumption = sc.nextInt();
                GregorianCalendar prevDate = new GregorianCalendar(pB.year,pB.month-1,pB.day);
                prevDate.add(Calendar.DATE,1);
                pB.setDate(prevDate);
                if(pB.equals(tB)){
                    conCount++;
                    totalConsum += tB.consumption - pB.consumption;
                }
                pB.copy(tB);
            }
            System.out.println(conCount + " " + totalConsum);

        }
        sc.close();
    }
}
