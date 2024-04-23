import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int days, dayOfMonth, month, year;
        while(true){
            days = sc.nextInt();
            dayOfMonth = sc.nextInt();
            month = sc.nextInt();
            year = sc.nextInt();
            if(days==0 && dayOfMonth==0 && month==0 && year==0){
                break;
            }
            GregorianCalendar cal = new GregorianCalendar(year,month-1,dayOfMonth);
            cal.add(Calendar.DATE,days);
            System.out.print(cal.get(Calendar.DATE)+ " ");
            System.out.print(cal.get(Calendar.MONTH)+1+" ");
            System.out.println(cal.get(Calendar.YEAR));
        }
    }
}
