#include <iostream>
#include <vector>
#include <string>

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::string s;
	std::cin >> s;

	int n = s.size();
	int z[n];
	int l = 1;
	z[0] = 0;

	for (int i = 1; i < n; ++i) {
		z[i] = std::max(0, std::min(z[i - l], z[l] + l - i));
		while (s[z[i]] == s[i + z[i]] and i + z[i] < n) {
			z[i] += 1;
		}
		if (i + z[i] > l + z[l]) {
			l = i;
		}
	}
	z[0] = n;

	for (int i = 0; i < n; ++i) {
		std::cout << z[i] << " ";
	}

	return 0;
}
