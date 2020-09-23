import java.util.Scanner;

public class Epi{
  public static int[] dir_flip = {2, 3, 0, 1};
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    final int CONN = 2*n + 2;
    Piece[] pieces = new Piece[n + 1];
    Piece border = new Piece();
    Piece start_corner = null;
    border.id = 0;
    int[] connections = new int[CONN]; // safety +2; should not be needed
    pieces[0] = border;
    connections[0] = 0;
    for(int i = 1; i < n + 1; i++) {
      Piece p = new Piece();
      pieces[i] = p;
      p.border = border;
      for(int j = 0; j < 4; j++) {
        int c = sc.nextInt();
        if(c == 0) {
          p.connected[j] = border;
        } else {
          if(connections[c] != 0) {
            int other = connections[c] % CONN;
            int other_dir = connections[c] / CONN;
            //System.err.println("Connected " + j + " from id " + i + " to " + other_dir + " from id " + pieces[other].id);
            p.connected[j] = pieces[other];
            pieces[other].connected[other_dir] = p;
          }
          else
            connections[c] = i + CONN * j;
        }
      }
      p.id = i;
      if(p.is_corner())
        start_corner = p;
    }
    connections = null; // help gc; redundant???

    if(start_corner == null) {
      System.out.println("impossible");
      return;
    }

    for(int i = 0; i < 4; i++) {
      if(start_corner.connected[i] == border && start_corner.connected[(i + 1) % 4] == border)
        start_corner.rotation = i;
    }

    Piece cur_p = start_corner;
    int cur_row = 1;
    int max_col = 1;
    int cur_col = 1;
    cur_p.row_id = cur_row;
    cur_p.column_id = cur_col++;
    Piece next_piece = cur_p.get_piece(3);
    //System.err.println("pieces: " + cur_p.id + " " + next_piece.id);
    while(next_piece != border) {
      next_piece.set_rotation(cur_p, 1);
      cur_p = next_piece;
      if(cur_p.get_piece(0) != border || cur_p.row_id != -1 || cur_p.column_id != -1) {
        System.out.println("impossible");
        return;
      }
      cur_p.row_id = cur_row;
      cur_p.column_id = cur_col++;
      next_piece = cur_p.get_piece(3);
    }
    max_col = cur_col - 1;
    
    Piece last_row_start = start_corner;
    Piece cur_row_start = start_corner.get_piece(2);
    while(cur_row_start != border) {
      cur_col = 1;
      cur_row++;
      cur_row_start.set_rotation(last_row_start, 0);
      if(cur_row_start.get_piece(1) != border || cur_row_start.row_id != -1 || cur_row_start.column_id != -1) {
        System.out.println("impossible");
        return;
      }
      cur_row_start.row_id = cur_row;
      cur_row_start.column_id = cur_col++;
      cur_p = cur_row_start;
      next_piece = cur_p.get_piece(3);
      while(next_piece != border) {
        next_piece.set_rotation(cur_p, 1);
        cur_p = next_piece;
        Piece above = cur_p.get_piece(0);
        if(above.row_id != cur_row -1 || above.column_id != cur_col || cur_p.row_id != -1 || cur_p.column_id != -1) {
          System.out.println("impossible");
          return;
        }
        cur_p.row_id = cur_row;
        cur_p.column_id = cur_col++;
        next_piece = cur_p.get_piece(3);
      }
      if(cur_col != max_col + 1) {
        System.out.println("impossible");
        return;
      }
      last_row_start = cur_row_start;
      cur_row_start = cur_row_start.get_piece(2);
    }

    if(max_col * cur_row != n) {
      System.out.println("impossible");
      return;
    }

    System.out.print(cur_row);
    System.out.print(" ");
    System.out.println(max_col);
    cur_row_start = start_corner;
    for(cur_row_start = start_corner; cur_row_start != border; cur_row_start = cur_row_start.get_piece(2)) {
      for(cur_p = cur_row_start; cur_p != border; cur_p = cur_p.get_piece(3)) {
        System.out.print(cur_p.id);
        System.out.print(' ');
      }
      System.out.println();
    }
  }

  public static class Piece {
    public Piece[] connected = {null, null, null, null}; // north, west, south, east
    public int rotation = -1;    // rotated clock-wise e.g. 1 => west->north; south->west...
    public int column_id = -1;
    public int row_id = -1;
    public int id;
    public Piece border;

    public Piece get_piece(int dir) {
      assert(rotation > -1);
      assert(dir > -1);
      return connected[(rotation + dir) % 4];
    }

    public boolean set_rotation(Piece p, int from) {
      //System.err.println("Piece " + p.id + " comes from " + from);
      for(int i = 0; i < 4; i++) {
        if(connected[i] == p) {
          int tmp_rot = (4 + i - from) % 4;
          if(rotation != -1 && tmp_rot != rotation)
            return false;
          rotation = tmp_rot;
          //System.err.println("Set rotation " + rotation + " to piece " + id);
          return true;
        }
      }
      assert(false);
      return false;
    }

    public boolean is_corner() {
      return (connected[0] == border || connected[2] == border) && (connected[1] == border || connected[3] == border);
    }
  }
}
