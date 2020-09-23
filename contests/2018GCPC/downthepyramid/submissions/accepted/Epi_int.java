import java.util.Scanner;

public class Epi_int{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int top = Integer.MAX_VALUE;
    int bottom = 0;
    int alt_sum = 0;
    for(int i = 0; i < n; i++) {
      alt_sum = sc.nextInt() - alt_sum;
      if(i % 2 == 0) {
        top = top > alt_sum ? alt_sum : top;
      } else {
        bottom = bottom < -alt_sum ? -alt_sum : bottom;
      }
    }
    if(top >= bottom)
      System.out.println(top - bottom + 1);
    else
      System.out.println(0);
  }     
}
