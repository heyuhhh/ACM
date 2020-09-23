import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

class alice {

	public static int[] data;
	public static int[] ld;
	public static int[][] imin;

	public static void initRMQ(){
		int N = data.length;
		ld = new int[N+1];
		imin = new int[32][N];
		ld[1] = 0;
		for (int i = 2; i < N+1; i++) {
			ld[i] = ld[i-1];
			if ((2 << ld[i]) <= i) ld[i]++;
		}
		for (int i = 0; i < N; i++) imin[0][i] = i;
		for (int j = 1; j < ld[N]+1; j++) for(int i = 0; i < N-(1 << j) + 1; i++){
			int i1 = imin[j-1][i];
			int i2 = imin[j-1][i + (1 << (j-1))];
			imin[j][i] = (data[i1] <= data[i2]) ? i1 : i2;
		}
	}

	public static int query(int a, int b){
		int n = ld[b-a];
		b -= (1 << n);
		return data[imin[n][a]] <= data[imin[n][b]] ? imin[n][a] : imin[n][b];
	}

	public static int l, w;

	public static int[] visitedNodes, depths, firstOccurences;
	public static int idx = 0;

	public static int[] dd = new int[4];

	public static void ldfs(int cur, int de, int par) {

		firstOccurences[cur] = idx; // First time cur is found in visitedNodes
		visitedNodes[idx] = cur; // Append node to visitedNodes
		depths[idx] = de;
		idx++;

		int b = adj[cur];
		for (int i = 0; i < 4; i++) {
			if((b & (1 << i)) != 0){
				int nei = cur + dd[i];
				if (nei == par) continue;
				ldfs(nei, de + 1, cur);
				visitedNodes[idx] = cur;
				depths[idx] = de;
				idx++;
			}
		}
	}

	public static void initLCA(int root){
		idx = 0;
		visitedNodes = new int[adj.length * 2];
		depths = new int[visitedNodes.length];
		firstOccurences = new int[visitedNodes.length];
		Arrays.fill(firstOccurences, -1);

		long start = System.currentTimeMillis();
		ldfs(root, 0, -1);
		//System.out.println("calc dfs " + (System.currentTimeMillis() - start));

		data = depths;
		initRMQ();
	}

	public static int LCA(int u, int v){
		if(u == v) return u;
		if(firstOccurences[u] > firstOccurences[v]){
			int tmp = u;
			u = v;
			v = tmp;
		}
		return visitedNodes[query(firstOccurences[u], firstOccurences[v] + 1)];
	}


	public static int[] adj;

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		l = scan.nextInt();
		w = scan.nextInt();

		dd[0] = -w;
		dd[1] = 1;
		dd[2] = w;
		dd[3] = -1;

		long start = System.currentTimeMillis();

		adj = new int[l*w];
		scan.nextLine();

		String last = scan.nextLine();
		for (int i = 1; i < l+1; i++) {
			String current = scan.nextLine();
			for (int j = 0; j < w; j++) {
				if(last.charAt(2*j+1) != '_') adj[(i-1)*w+j] |= 1; //north
				if(current.charAt(2*j+1) != '_') adj[(i-1)*w+j] |= 4; //south
				if(current.charAt(2*j) != '|') adj[(i-1)*w+j] |= 8; //west
				if(current.charAt(2*j+2) != '|') adj[(i-1)*w+j] |= 2; //east
				//System.out.println((i-1) + "|" + j + ": " + adj[i-1][j]);
			}
			last = current;
		}

		//System.out.println("input read " + (System.currentTimeMillis() - start));

		int places = scan.nextInt();

		int[] xs = new int[places];
		int[] ys = new int[places];

		for (int i = 0; i < places; i++) {
			int y = scan.nextInt();
			int x = scan.nextInt();
			xs[i] = --y;
			ys[i] = --x;
		}

		long erg = 0;

		start = System.currentTimeMillis();
		initLCA(xs[0] * w + ys[0]);
		//System.out.println("init LCA " + (System.currentTimeMillis() - start));

		start = System.currentTimeMillis();
		for (int i = 0; i < places-1; i++){
			int l1 = xs[i] * w + ys[i];
			int l2 = xs[i+1] * w + ys[i+1];

			int d1 = depths[firstOccurences[l1]];
			int d2 = depths[firstOccurences[l2]];
			int diff = depths[firstOccurences[LCA(l1, l2)]];

			erg += d1 + d2 - 2 * diff;
		}
		//System.out.println("answer queries " + (System.currentTimeMillis() - start));

		System.out.println(erg);
	}
}
