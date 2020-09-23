import java.util.Scanner;
import java.util.HashSet;

public class Epi{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int monsters[] = new int[n];
    HashSet<Integer> set = new HashSet<Integer>();
    int contains_one = -1;
    for(int i = 0; i < n; i++) {
      int m = sc.nextInt();
      if(m == 1) {
        if(contains_one == -1)
          contains_one = i+1;
        else {
          System.out.println(contains_one + " " + (i+1));
          return;
        }
      }
      monsters[i] = m;
      set.add(new Integer(m));
    }
    int a = 1, b = 2;
    boolean possible = false;
    while(b <= 1000*1000) {
      if(set.contains(a) && set.contains(b)) {
        possible = true;
        break;
      }
      int tmp = b;
      b += a;
      a = tmp;
   }
   if(!possible) {
     System.out.println("impossible");
     return;
   }
   int ind_i = 0, ind_j = 0;
   for(int i = 0; i < n; i++) {
     if(monsters[i] == a) ind_i = i+1;
     if(monsters[i] == b) ind_j = i+1;
   }
   System.out.println(ind_i + " " + ind_j);

  } 
}
