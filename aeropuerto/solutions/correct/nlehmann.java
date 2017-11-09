/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */
import java.util.*;
import java.io.*;

public class nlehmann {

    static int N;
    static ArrayList<Edge> paths[];
    static ArrayList<Train> trains[];

    static int dijkstra(int S, int T) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int dist[] = new int[N];
        for (int i = 0; i < N; ++i)
            dist[i] = 1000000000;
        dist[S] = 0;
        pq.offer(new Pair(0, S));
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int d = p.x;
            int n = p.y;

            if (d > dist[n])
                continue;

            if (n == T)
                return d;

            for (Edge path : paths[n]) {
                int v = path.v;
                int w = path.w;
                if (w + d < dist[v]) {
                    dist[v] = w + d;
                    pq.offer(new Pair(w + d, v));
                }
            }
            for (Train train : trains[n]) {
                if (train.t >= d) {
                    int v = train.v;
                    int w = train.t + train.w;
                    if (w < dist[v]) {
                        dist[v] = w + d;
                        pq.offer(new Pair(w, v));
                    }
                }
            }
        }
        return -1;
    }

    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(in.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        S--; T--;

        paths = new ArrayList[N];
        for (int i = 0; i < N; ++i)
            paths[i] = new ArrayList<>();
        for (int i = 0; i < M; ++i) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            a--; b--;
            paths[a].add(new Edge(a, b, c));
            paths[b].add(new Edge(b, a, c));
        }

        st = new StringTokenizer(in.readLine());
        int P = Integer.parseInt(st.nextToken());
        trains = new ArrayList[N];
        for (int i = 0; i < N; ++i)
            trains[i] = new ArrayList<>();
        for (int i = 0; i < P; ++i) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            u--; v--;
            trains[u].add(new Train(u, v, t, w));
        }

        System.out.println(dijkstra(S, T));
    }
}

class Edge {
    public int u, v, w;
    public Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

class Train {
    public int u, v, t, w;
    public Train(int u, int v, int t, int w) {
        this.u = u;
        this.v = v;
        this.t = t;
        this.w = w;
    }
}

class Pair implements Comparable<Pair> {
    public int x, y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int compareTo(Pair p) {
        if (x == p.x)
            return y - p.y;
        return x - p.x;
    }
}
