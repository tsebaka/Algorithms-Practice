#include <iostream>

int main() {
	long n;
	std::cin >> n;

	long a[n + 1];
	long ans = 0;
	long minx = 0;
	long sum = 0;
	long maxx = -10000000;
	long l;
	long r;

	int min_pos = -1;
	l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum += a[i];

		if (maxx < sum - minx) {
			maxx = sum - minx;
			r = i;
			l = min_pos + 1;
		}
		if (minx > sum) {
			minx = sum;
			min_pos = i;
		}
	}

	if (n == 1) {
		std::cout << 1 << " " << 1 << " " << a[0];
		return 0;
	}
	std::cout << min(l, r) + 1 << " " << max(l, r) + 1 << " " << maxx << "\n";


	return 0;
}
