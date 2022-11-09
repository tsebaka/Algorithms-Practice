#include <iostream>

int main() {

	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int suff_array[n];
	int pos[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> suff_array[i];
		pos[suff_array[i] - 1] = i;
		suff_array[i] -= 1;
	}

	int lcp[n - 1];
	int k;
	int next;

	k = 0;

	for (int i = 0; i < n; ++i) {
		k = std::max(0, k - 1);

		if (pos[i] == n - 1) continue;
		next = suff_array[pos[i] + 1];
		while (str[i + k] ==
		        str[next + k]) {
			k += 1;
		}
		lcp[pos[i]] = k;
	}

	for (int i = 0; i < n - 1; ++i)
		std::cout << lcp[i] << " ";

}