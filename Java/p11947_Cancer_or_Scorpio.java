import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(), cs = 1;
        String inp;
        while(t-- > 0){
            inp = sc.next();
            int month = Integer.parseInt(inp.substring(0,2));
            int day = Integer.parseInt(inp.substring(2,4));
            int year = Integer.parseInt(inp.substring(4));
            GregorianCalendar cal = new GregorianCalendar(year,month-1,day);
            cal.add(Calendar.DATE,40*7);
            month = cal.get(Calendar.MONTH)+1;
            day = cal.get(Calendar.DATE);
            year = cal.get(Calendar.YEAR);
            System.out.print((cs++) + " ");
            System.out.print((month>9 ? month : "0" + month)+"/");
            System.out.print((day>9 ? day : "0" + day)+"/");
            System.out.print(year + " ");
            if((month==1 && day>=21) || (month==2 && day<=19)){
                System.out.println("aquarius");
            }
            else if((month==2 && day>=20) || (month==3 && day<=20)){
                System.out.println("pisces");
            }
            else if((month==3 && day>=21) || (month==4 && day<=20)){
                System.out.println("aries");
            }
            else if((month==4 && day>=21) || (month==5 && day<=21)){
                System.out.println("taurus");
            }
            else if((month==5 && day>=22) || (month==6 && day<=21)){
                System.out.println("gemini");
            }
            else if((month==6 && day>=22) || (month==7 && day<=22)){
                System.out.println("cancer");
            }
            else if((month==7 && day>=23) || (month==8 && day<=21)){
                System.out.println("leo");
            }
            else if((month==8 && day>=22) || (month==9 && day<=23)){
                System.out.println("virgo");
            }
            else if((month==9 && day>=24) || (month==10 && day<=23)){
                System.out.println("libra");
            }
            else if((month==10 && day>=24) || (month==11 && day<=22)){
                System.out.println("scorpio");
            }
            else if((month==11 && day>=23) || (month==12 && day<=22)){
                System.out.println("sagittarius");
            }
            else {
                System.out.println("capricorn");
            }
        }
    }
}
