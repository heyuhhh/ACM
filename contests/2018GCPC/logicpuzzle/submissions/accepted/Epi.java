import java.util.Scanner;

public class Epi{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    int mosaic[][] = new int[h + 2][w + 2];
    boolean mosaic_marked[][] = new boolean[h + 2][w + 2];
    for(int i = 0; i < h + 2; i++) {
      for(int j = 0; j < w + 2; j++) {
        mosaic[i][j] = sc.nextInt();
      }
    }
    for(int y = 1; y < h + 1; y++) {
      for(int x = 1; x < w + 1; x ++) {
        if(mosaic[y - 1][x - 1] > 0) {
        mosaic_marked[y][x] = true;
          for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
              mosaic[y + i][x + j] -= 1;
            }
          }
        }
      }
    }
    for(int i = 0; i < h + 2; i++) {
      for(int j = 0; j < w + 2; j++) {
        if(mosaic[i][j] != 0) {
          System.out.println("impossible");
          return;
        }
      }
    }

    for(int y = 1; y < h + 1; y++) {
      for(int x = 1; x < w + 1; x ++) {
        if(mosaic_marked[y][x])
          System.out.print('X');
        else
          System.out.print('.');
      }
      System.out.println();
    }
  }     
}
