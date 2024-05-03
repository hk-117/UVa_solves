import java.util.*;

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
        int h1,h2,m1,m2;
        while(true){
            h1 = sc.nextInt();
            m1 = sc.nextInt();
            h2 = sc.nextInt();
            m2 = sc.nextInt();
            if(h1==0 && m1==0 && h2==0 && m2==0){
                break;
            }
            Time a = new Time(h1, m1);
            Time b = new Time(h2, m2);
            System.out.println(b.difference(a));
        }
        sc.close();
    }
}
