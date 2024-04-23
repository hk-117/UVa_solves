import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int start, first, second, third;
        while(true){
            start = sc.nextInt();
            first = sc.nextInt();
            second = sc.nextInt();
            third = sc.nextInt();
            if(start==0 && first == 0 && second == 0 && third==0){
                break;
            }
            int result = 1080;
            if(start < first){
                result += 9 * (40 + start - first);
            }else{
                result += 9 * (start - first);
            }
            if(first < second){
                result += 9 * (second - first);
            } else {
                result += 9 * (40 + second - first);
            }
            if(second < third){
                result += 9 * (40 + second - third);
            }else{
                result += 9 * (second - third);
            }
            System.out.println(result);
        }
    }
}
