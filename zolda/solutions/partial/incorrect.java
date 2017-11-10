import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class incorrect {
	static int n;
	static long k;
	static long[] x, y;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Long.parseLong(st.nextToken());
		x = new long[n];
		y = new long[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			x[i] = Long.parseLong(st.nextToken());
			y[i] = Long.parseLong(st.nextToken());
		}
		System.out.println(binarySearch(0L, 100000L));
	}

	private static long binarySearch(long l, long r) {
		while (l < r) {
			long mid = (l + r) / 2;
			if (count(mid) >= k)
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}

	private static long count(long r) {
		long ans = 0;
		for (long i = 0; i <= r; i++) {
			long j = (long) Math.floor(Math.sqrt(r * r - i * i));
			if (i == 0) {
				ans += 2 * j;
				ans += 1;
			} else {
				ans += 4 * j;
				ans += 2;
			}
			
		}
		for (int i = 0; i < n; i++) {
			if (x[i] * x[i] + y[i] * y[i] <= r)
				ans--;
		}
		return ans - 1;
	}
}
