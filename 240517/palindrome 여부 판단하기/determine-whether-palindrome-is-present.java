import java.util.*;

public class Main {

    public static void f(String s) {
        int l=0,r=s.length()-1;
        while (l<=r) {
            if (s.charAt(l)!=s.charAt(r)) {
                System.out.println("No");
                return;
            }
            l++;
            r--;
        }
        System.out.println("Yes");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        f(str);
    }
}