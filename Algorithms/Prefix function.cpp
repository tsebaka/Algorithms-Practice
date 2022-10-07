#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::string s;
	std::cin >> s;
	size_t n = s.size();
	int pos;
	int pref[n + 1];

	pref[0] = -1;
	pref[1] = 0;

	for (size_t i = 1; i <= n; ++i) {
		pos = pref[i - 1];

		while (pos != -1 && s[pos] != s[i - 1]) {
			pos = pref[pos];
		}
		pref[i] = pos + 1;
	}

	for (int i = 1; i <= n; ++i) {
		std::cout << pref[i] << " ";
	}


	return 0;
}
