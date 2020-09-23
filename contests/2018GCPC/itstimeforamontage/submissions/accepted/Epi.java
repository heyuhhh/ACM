import java.util.Scanner;

public class Epi{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int heroes[] = new int[n];
    int villains[] = new int[n];
    for(int i = 0; i < n; i++) {
      heroes[i] = sc.nextInt();
    }
    for(int i = 0; i < n; i++) {
      villains[i] = sc.nextInt();
    }
    int days_equal = villains[0] - heroes[0];
    if(days_equal < 0) {
      System.out.println(0);
      return;
    }
    for(int i = 1; i < n; i++) {
      int new_power = heroes[i] + days_equal;
      if(new_power < villains[i]) {
        System.out.println(days_equal + 1);
        return;
      }
      if(new_power > villains[i]) {
        System.out.println(days_equal);
        return;
      }
    }
    System.out.println(days_equal);
  }     
}
