import java.util.*;
import java.math.*;

class RGR {
	long max = 1_000_000_000_000_000L;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		long num = s.nextLong();
		if(num == 1) {
			System.out.println("3 1");
			return;
		}
		num--;
		for(int dim = 3;; dim++) {
			BigInteger bnum = BigInteger.valueOf(num);
			BigInteger bi = BigInteger.ONE;
			while(bnum.longValue() > 0) {
				bi = bi.add(BigInteger.ONE);
				bnum = bnum.subtract(bi.pow(dim-1));
			}
			if(bnum.longValue() == 0) {
				System.out.println(dim + " " + bi.longValue());
				return;
			}
			if(bi.longValue() == 2) {
				System.out.println("impossible");
				return;
			}
		}
	}
}
