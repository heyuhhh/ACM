import java.util.Scanner;
import java.util.TreeSet;

public class Epi_sort{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    TreeSet<Pair> set = new TreeSet<Pair>();
    for(int i = 0; i < n; i++) {
      set.add(new Pair(sc.nextInt(), i+1));
    }

    Pair old = null;
    int a = 1, b = 1, tmp;
    for(Pair p : set) {
      while(b < p.val) {
        tmp = b;
        b += a;
        a = tmp;
      }
      if(old != null) {
        if(b == p.val && a == old.val) {
          System.out.println(old.pos + " " + p.pos);
          return;
        }
      }
      if(p.val == b)
        old = p;
    }
    System.out.println("impossible");
  } 

  public static class Pair implements Comparable{
    int val, pos;

    public Pair(int val, int pos) {
      this.val = val;
      this.pos = pos;
    }

    @Override
    public int compareTo(Object obj) {
      Pair b = (Pair) obj;
      if(this.val == b.val) return this.pos - b.pos;
      return this.val - b.val;
    }
  }
}
