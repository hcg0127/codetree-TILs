import java.util.*;

class Password {
    String x;
    String y;
    int z;

    public Password(String q, String w, int e) {
        this.x = q;
        this.y = w;
        this.z = e;
    }

    public void scodePrint() {
        System.out.println("secret code : " + this.x);
    }

    public void mpointPrint() {
        System.out.println("meeting point : " + this.y);
    }

    public void timePrint() {
        System.out.println("time : " + this.z);
    }
};

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();
        int c = sc.nextInt();
        
        Password pw = new Password(a,b,c);
        pw.scodePrint();
        pw.mpointPrint();
        pw.timePrint();
    }
}