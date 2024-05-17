import java.util.*;

class IntWrapper {
    int value;

    public IntWrapper(int value) {
        this.value = value;
    }
}

public class Main {

    public static void f(IntWrapper a, IntWrapper b) {
        int tmp = a.value;
        a.value = b.value;
        b.value = tmp;
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        IntWrapper intn = new IntWrapper(n);
        IntWrapper intm = new IntWrapper(m);
        
        f(intn,intm);
        System.out.println(intn.value + " " + intm.value);
    }
}