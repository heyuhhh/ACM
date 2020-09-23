import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.math.*;

class alice_arraylist_duplicates {

	public static int expected_len;
	public static int maxlen = 2005;
	public static int oo = 100000;
	public static double eps = 1e-10;

	public static class IntHashSet extends ArrayList<Integer>{}

	// length -> minimal number of wires
	public static IntHashSet[] calc(ArrayList<Integer> wires){
		IntHashSet[][] dp = new IntHashSet[wires.size()][maxlen];
		for (int j = 0; j < maxlen; j++) {
			dp[0][j] = new IntHashSet();
		}

		dp[0][0].add(0);
		dp[0][wires.get(0)].add(1);
		for (int i = 1; i < wires.size(); i++) {
			for (int j = 0; j < maxlen; j++){
				dp[i][j] = (IntHashSet)dp[i-1][j].clone();
				if(wires.get(i) <= j){
					for(Integer ww : dp[i-1][j-wires.get(i)]){
						dp[i][j].add(ww + 1);
					}
				}
			}
		}

		return dp[wires.size()-1];
	}


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int d = scan.nextInt();
		expected_len = d;

		ArrayList<Integer> wires = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int r = scan.nextInt();
			wires.add(r);
		}

		IntHashSet[] erg = calc(wires);

		double maxdist = -1;

		int exp_val = d - 10;
		for (int i = exp_val; i < maxlen; i++) {
			int dist = (i - exp_val);
			for(int nums : erg[i]){
				int num_touch = nums + 1;
				if(num_touch * 5 < dist) continue;
				double diff = ((double)dist)/num_touch;
				maxdist = Math.max(maxdist, diff);
			}
		}

		if(maxdist < 0){
			System.out.println("impossible");
		} else {
			System.out.format("%2.10f", maxdist);
		}
	}

}
