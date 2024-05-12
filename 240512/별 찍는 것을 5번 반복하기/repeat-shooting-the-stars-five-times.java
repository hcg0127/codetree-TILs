public class Main {

    public static void printStar() {
        for (int i=0; i<10; i++)
            System.out.print("*");
    }

    public static void main(String[] args) {
        for (int i=0; i<5; i++) {
            printStar();
            System.out.println();
        }
    }
}