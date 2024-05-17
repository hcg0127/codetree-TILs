import java.util.*;

public class Main {

    public static void f(int a, int b) {
        int tmp = a;
        a = b;
        b = tmp;
        System.out.println(a + " " + b);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,m;
        n = sc.nextInt();
        m = sc.nextInt();
        f(n,m);
        
    }
}