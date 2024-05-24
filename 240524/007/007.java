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
};

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();
        int c = sc.nextInt();
        
        Password pw = new Password(a,b,c);
        System.out.println("secret code : " + pw.x);
        System.out.println("meeting point : " + pw.y);
        System.out.println("time : " + pw.z);
    }
}