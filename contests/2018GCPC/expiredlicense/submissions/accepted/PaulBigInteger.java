import java.math.*;
import java.util.*;

public class PaulBigInteger {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		while (tc --> 0) {
			BigInteger a = BigInteger.valueOf(Math.round(sc.nextDouble() * 1e5));
			BigInteger b = BigInteger.valueOf(Math.round(sc.nextDouble() * 1e5));
			if (a.equals(b)) {
				System.out.println("2 2");
			} else {
				BigInteger g = a.gcd(b);
				a = a.divide(g);
				b = b.divide(g);
				if (a.isProbablePrime(30) && b.isProbablePrime(30)) {
					System.out.println(a + " " + b);
				} else {
					System.out.println("impossible");
				}
			}
		}
	}
}
