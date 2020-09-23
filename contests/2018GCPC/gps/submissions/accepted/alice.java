import java.util.Scanner;
import java.util.Locale;
import java.math.*;


public class alice {

	final static long EARTH_RAD = 6371;
	final static double EPS = 1e-9;
	final static BigDecimal LIGHT_SPEED = new BigDecimal("299792.458");

	public static BigDecimal[][] doubleToBigTecArr(double[][] d){
		BigDecimal[][] mat = new BigDecimal[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if(Math.abs(d[i][j]) < EPS) mat[i][j] = BigDecimal.ZERO;
				else if(Math.abs(d[i][j]-1) < EPS) mat[i][j] = BigDecimal.ONE;
				else mat[i][j] = new BigDecimal(d[i][j]);
			}
		}
		return mat;
	}

	public static class Matrix {
		BigDecimal[][] mat;

		public Matrix(){
			mat = new BigDecimal[3][3];
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					mat[i][j] = i == j ? BigDecimal.ONE : BigDecimal.ZERO;
				}
			}
		}


		public Point mult(Point p){
			BigDecimal[] r = new BigDecimal[3];
			for (int i = 0; i < 3; i++) {
				r[i] = BigDecimal.ZERO;
				for (int j = 0; j < 3; j++) {
					r[i] = r[i].add(mat[i][j].multiply(p.p[j]));
				}
			}
			return new Point(r[0], r[1], r[2]);
		}
	}

	public static class Point {
		BigDecimal[] p = new BigDecimal[3];

		public Point(double x, double y, double z){
			this(new BigDecimal(x), new BigDecimal(y), new BigDecimal(z));
		}

		public Point(BigDecimal x, BigDecimal y, BigDecimal z){
			p[0] = x;
			p[1] = y;
			p[2] = z;
		}


	}

	public static void main(String[] args) {
		Locale.setDefault(new Locale("en", "US"));
		BigDecimal LIGHT_SPEED_SQUARED = LIGHT_SPEED.multiply(LIGHT_SPEED);
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		double lo = Math.toRadians(scan.nextDouble());
		double la = Math.toRadians(scan.nextDouble());

		BigDecimal px = new BigDecimal(EARTH_RAD * Math.cos(la) * Math.cos(lo));
		BigDecimal py = new BigDecimal(EARTH_RAD * Math.cos(la) * Math.sin(lo));
		BigDecimal pz = new BigDecimal(EARTH_RAD * Math.sin(la));

		Matrix m1 = new Matrix();
		Matrix m2 = new Matrix();
		Matrix m3 = new Matrix();

		for (int i = 0; i < t; i++) {
			double phi = Math.toRadians(scan.nextDouble());
			double v = Math.toRadians(scan.nextDouble() - 90);
			double r = scan.nextDouble();
			double p = scan.nextDouble() * 2 * Math.PI;
			p *= -1;

			double xs = EARTH_RAD * Math.sin(lo) * Math.cos(la);

			Point s = new Point(r, 0, 0);

			m1.mat[0][0] = new BigDecimal(Math.cos(p));
			m1.mat[0][2] = new BigDecimal(Math.sin(p));
			m1.mat[2][0] = new BigDecimal(-Math.sin(p));
			m1.mat[2][2] = new BigDecimal(Math.cos(p));

			m2.mat[1][1] = new BigDecimal(Math.cos(v));
			m2.mat[1][2] = new BigDecimal(-Math.sin(v));
			m2.mat[2][1] = new BigDecimal(Math.sin(v));
			m2.mat[2][2] = new BigDecimal(Math.cos(v));

			m3.mat[0][0] = new BigDecimal(Math.cos(phi));
			m3.mat[0][1] = new BigDecimal(-Math.sin(phi));
			m3.mat[1][0] = new BigDecimal(Math.sin(phi));
			m3.mat[1][1] = new BigDecimal(Math.cos(phi));

			s = m1.mult(s);
			s = m2.mult(s);
			s = m3.mult(s);

			BigDecimal x = s.p[0];
			BigDecimal y = s.p[1];
			BigDecimal z = s.p[2];

			BigDecimal dx = (x.subtract(px));
			BigDecimal dy = (y.subtract(py));
			BigDecimal dz = (z.subtract(pz));

			if(dx.multiply(px).add(dy.multiply(py)).add(dz.multiply(pz)).signum() <= 0){
				System.out.println("no signal");
			} else {
				BigDecimal sqared_dist = dx.multiply(dx).add(dy.multiply(dy)).add(dz.multiply(dz));

				BigDecimal dist = sqared_dist.divide(LIGHT_SPEED_SQUARED, 10, BigDecimal.ROUND_UP);
				System.out.format("%10.10f\n", Math.sqrt(dist.doubleValue()));
			}
		}
	}
}
