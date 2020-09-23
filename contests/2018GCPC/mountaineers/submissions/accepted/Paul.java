import java.util.*;

public class Paul {

	class Node implements Comparable<Node> {
		int height;
		Node parent;
		Set<Integer> mountaineers;
		List<Node> neighbours;

		Node find() {
			if (this != parent) parent = parent.find();
			return parent;
		}
		
		void merge() {
			for (Node a: neighbours) {
				if (a.height <= height) union(this,a);
			}
		}

		Node(int height) {
			this.height = height;
			this.parent = this;
			this.mountaineers = new TreeSet<Integer>();
			this.neighbours = new ArrayList<Node>();
		}
		
		public int compareTo(Node a) {
			return Integer.compare(height,a.height);
		}
	}
	
	void union(Node a, Node b) {
		a = a.find();
		b = b.find();
		if (a == b) return;

		if (a.mountaineers.size() > b.mountaineers.size()) {
			Node c = a;
			a = b;
			b = c;
		}

		a.parent = b;
		b.height = Math.max(a.height,b.height);
		for (int k: a.mountaineers) {
			if (b.mountaineers.contains(k)) {
				res[k] = b.height;
			} else {
				b.mountaineers.add(k);
			}
		}
		a.mountaineers.clear();
	}
	
	int[] res;
	void run() {
		Scanner sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		int q = sc.nextInt();
		
		Node[][] nodes = new Node[m][n];
		List<Node> nodeList = new ArrayList<Node>();
		res = new int[q];

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int height = sc.nextInt();
				nodes[i][j] = new Node(height);
				nodeList.add(nodes[i][j]);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i > 0)   nodes[i][j].neighbours.add(nodes[i-1][j]);
				if (j > 0)   nodes[i][j].neighbours.add(nodes[i][j-1]);
				if (i+1 < m) nodes[i][j].neighbours.add(nodes[i+1][j]);
				if (j+1 < n) nodes[i][j].neighbours.add(nodes[i][j+1]);
			}
		}
		
		for (int k = 0; k < q; k++) {
			for (int t = 0; t < 2; t++) {
				Node a = nodes[sc.nextInt()-1][sc.nextInt()-1];
				if (a.mountaineers.contains(k)) {
					res[k] = a.height;
				} else {
					a.mountaineers.add(k);
				}
			}
		}
		
		Collections.sort(nodeList);
		for (Node a: nodeList) a.merge();
		for (int x: res) System.out.println(x);
	}

	public static void main(String[] args) {
		new Paul().run();
	}
}
