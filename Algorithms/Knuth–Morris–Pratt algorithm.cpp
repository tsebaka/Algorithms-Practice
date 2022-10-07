#include <iostream>
#include <string>
#include <vector>

int main() {

	std::string text;
	std::string word;
	std::cin >> text >> word;
	std::string concat = word + "#" + text;
	std::vector<long> pref(concat.size() + 1);
	pref[0] = -1;
	pref[1] = 0;
	long k;

	for (int i = 1; i <= concat.size(); ++i) {
		k = pref[i - 1];
		while (k != -1 && concat[k] != concat[i - 1]) {
			k = pref[k];
		}
		pref[i] = k + 1;
	}

	int cnt;
	std::vector<int> ans;

	for (int i = 0; i < pref.size(); ++i) {
		if (word.size() == pref[i]) {
			cnt += 1;
			ans.push_back(i - 2 * word.size());
		}
	}

	std::cout << cnt << "\n";
	for (auto i : ans) {
		std::cout << i << " ";
	}

	return 0;
}
