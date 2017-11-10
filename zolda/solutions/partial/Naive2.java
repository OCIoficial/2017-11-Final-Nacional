import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Naive2 {
	static int n;
	static long k;
	static int[] x, y;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Long.parseLong(st.nextToken());
		x = new int[n];
		y = new int[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
		}
		long r = 1;
		while (count(r) < k) 
			r+=r;
		System.out.println(binarySearch(0L, r));
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
		long ans = 4*r;
		for (long i = 1; i <= r; i++) {
			for (long j = 1; j <= r; j++) {
				if (i * i + j * j <= r * r)
					ans+=4;
			}
		}
		for (int i = 0; i < n; i++) {
			if (x[i] * x[i] + y[i] * y[i] <= r * r)
				ans--;
		}
		return ans;
	}
}