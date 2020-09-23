import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

/**
 * Linear-time solution to HeliSkiing for the GCPC 2018 written by Christian Müller.
 * Computes shortest path from any source to any sink.
 */
public class HeliskiingChrisSP {

    public static void main(String[] args) {

        FastScanner scan = new FastScanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();
        n += 2;
        final int SOURCE = 0;
        final int SINK = n - 1;

        HashMap<Integer, HashMap<Integer, Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new HashMap<>());
        }
        int[] inc = new int[n];
        for (int i = 0; i < m; i++) {
            int from = scan.nextInt();
            int to = scan.nextInt();
            int dist = scan.nextInt();
            graph.get(from).put(to, dist);
            inc[to]++;
        }
        for (int i = 1; i < n - 1; i++) {
            if (inc[i] == 0) {
                graph.get(SOURCE).put(i, 0);
                inc[i]++;
            }
            if (graph.get(i).isEmpty()) {
                graph.get(i).put(SINK, 0);
                inc[SINK]++;
            }
        }

        // topsort distances
        Queue<Integer> queue = new LinkedList<>();
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[SOURCE] = 0;
        queue.add(SOURCE);
        while(!queue.isEmpty()) {
            int next = queue.poll();
            for (Map.Entry<Integer, Integer> out : graph.get(next).entrySet()) {
                if (dist[out.getKey()] > dist[next] + out.getValue()) {
                    dist[out.getKey()] = dist[next] + out.getValue();
                }
                --inc[out.getKey()];
                if (inc[out.getKey()] == 0) {
                    queue.add(out.getKey());
                }
            }
        }
        System.out.println(dist[SINK]);
    }

    static class FastScanner {
        BufferedReader br = null;
        StringTokenizer st = null;

        FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

}
