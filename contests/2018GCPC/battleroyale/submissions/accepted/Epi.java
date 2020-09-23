import java.util.Scanner;

public class Epi{

  public static double distance_to_tangent_point(Coord a, Circle b) {
    return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2) - (b.r * b.r));
  }

  public static double distance_squared(Coord a, Coord b) {
    return Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2);
  }

  public static Coord[] circle_x_circle(Circle a, Circle b) {
    Coord result[] = new Coord[2];
    result[0] = new Coord();
    result[1] = new Coord();
    double dx = b.x - a.x, dy = b.y - a.y;
    double d = Math.sqrt(dx*dx + dy*dy);
    double x = (d*d + a.r*a.r - b.r*b.r) / (2*d);
    double y = Math.sqrt(Math.abs(a.r*a.r - x*x));
    result[0].x = a.x + (x*dx - y*dy) / d; result[0].y = a.y + (x*dy + y*dx) / d;
    result[1].x = a.x + (x*dx + y*dy) / d; result[1].y = a.y + (x*dy - y*dx) / d;
    return result;
  }

  public static double arc_calc(Coord a, Coord b, Circle c) {
    double d = distance_squared(a, b);
    return c.r * Math.acos(1 - (d/(2*Math.pow(c.r,2))));
  }



  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Coord position = new Coord();
    Coord target = new Coord();
    Circle blue = new Circle();
    Circle red = new Circle();
    
    position.x = sc.nextDouble(); position.y = sc.nextDouble();
    target.x = sc.nextDouble(); target.y = sc.nextDouble();
    
    blue.x = sc.nextDouble(); blue.y = sc.nextDouble(); blue.r = sc.nextDouble();
    red.x = sc.nextDouble(); red.y = sc.nextDouble(); red.r = sc.nextDouble();

    Circle pos_c = new Circle(); pos_c.x = position.x; pos_c.y = position.y;
    Circle tgt_c = new Circle(); tgt_c.x = target.x; tgt_c.y = target.y;
    

    pos_c.r = distance_to_tangent_point(position, red);
    tgt_c.r = distance_to_tangent_point(target, red);

    Coord cut_pos[] = circle_x_circle(pos_c, red);
    Coord cut_tgt[] = circle_x_circle(tgt_c, red);
    
    double result = 1000*1000*1000;

    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) result = Math.min(result, arc_calc(cut_pos[i], cut_tgt[j], red));
    
    result += pos_c.r + tgt_c.r;

    System.out.println(String.format("%.6f", result));

  } 
  
  public static class Coord {
    public double x, y;
    public String toString() {
      return "(" + x + " / " + y + ")";
    }
  }

  public static class Circle {
    public double x, y, r;
    public String toString() {
      return "(" + x + " / " + y + ") r: " + r;
    }
  }
}
