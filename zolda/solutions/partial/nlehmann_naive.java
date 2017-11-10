import java.util.*;
import java.io.*;


public class nlehmann_naive {
    static ArrayList<Point> not_meblins = new ArrayList<>();

    static int pointsInCircle(int R) {
        int points = 0;
        for (int i = -R; i <= R; ++i)
            for (int j = -R; j <= R; ++j)
                if (new Point(i, j).norm2() <= R*R)
                    points += 1;
        return points - 1;
    }

    static int emptyPoints(int R) {
        int sum = 0;
        for (Point p : not_meblins)
            if (p.norm2() <= R*R)
                sum += 1;
        return sum;
    }

    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(in.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());
            not_meblins.add(new Point(X, Y));
        }

        int r = 1;
        while(pointsInCircle(r) - emptyPoints(r) < K)
            r++;

        System.out.println(r);
    }
}

class Point {
    public int x, y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int norm2() {
        return x*x + y * y;
    }
}
