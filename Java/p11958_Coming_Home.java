import java.util.Scanner;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        class Time{
            int H;
            int M;
            public Time(int h, int m){
                this.H = h;
                this.M = m;
            }
            public int difference (Time t){
                int hDiff, mDiff;
                if(this.H > t.H){
                    hDiff = this.H - t.H;
                    mDiff = this.M - t.M;
                } else if(this.H == t.H){
                    if(this.M < t.M){
                        hDiff = 24 + (this.H - t.H);
                        mDiff = this.M - t.M;
                    }else{
                        hDiff = 0;
                        mDiff = this.M - t.M;
                    }
                } else {
                    hDiff = 24 + (this.H - t.H);
                    mDiff = this.M - t.M;
                }
                return (hDiff*60+mDiff);
            }
        }
        int t = sc.nextInt();
        for(int cs = 1; cs<=t; cs++){
            int minTime = Integer.MAX_VALUE;
            int k,q;
            String hr;
            StringTokenizer tok;
            k = sc.nextInt();
            hr = sc.next();
            tok = new StringTokenizer(hr,":");
            Time currentTime = new Time(Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()));
            while(k-- > 0){
                hr = sc.next();
                q = sc.nextInt();
                tok = new StringTokenizer(hr,":");
                Time tmpTime = new Time(Integer.parseInt(tok.nextToken()),Integer.parseInt(tok.nextToken()));
                if(tmpTime.difference(currentTime) + q < minTime){
                    minTime = tmpTime.difference(currentTime)+q ;
                }
            }
            System.out.println("Case " + cs + ": " + minTime);
        }
        sc.close();
    }
}
