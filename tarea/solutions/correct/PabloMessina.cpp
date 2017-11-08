#include <bits/stdc++.h>
int main() {
	int n;
	scanf("%d", &n);
	int lines = 1;
	int num_digits = 1;
	int ten_power = 10;
	int length = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == ten_power) {
			ten_power *= 10;
			num_digits++;
		}
		if (length + num_digits > 28) {
			length = 0;
			lines++;
		}
		length += num_digits;
	}
	printf("%d\n", (lines/35) + (lines%35 > 0));
	return 0;
}