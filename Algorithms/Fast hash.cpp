#include <iostream>
#include <vector>
#include <string>

const long long p = 31;
std::vector<long> P;
std::vector<long> p_pows;


long fast_hash (int l, int r) {
	return (P[r + 1] - P[l] * p_pows[r - l + 1]);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::string s;
	int n;
	std::cin >> s;
	std::cin >> n;

	int l1, r1;
	int l2, r2;
	long hs1;
	long hs2;
	size_t sz = s.size();

	P.resize(sz + 1);
	p_pows.resize(sz + 1);
	P[0] = 0;
	p_pows[0] = 1;

	for (int i = 0; i < sz; ++i) {
		P[i + 1] = (P[i] * p + s[i]);
		p_pows[i + 1] = p_pows[i] * p;
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> l1 >> r1 >> l2 >> r2;
		hs1 = fast_hash(l1 - 1, r1 - 1);
		hs2 = fast_hash(l2 - 1, r2 - 1);
		if (hs1 == hs2) {
			std::cout << "Yes" << "\n";
		} else {
			std::cout << "No" << "\n";
		}
	}

	return 0;
}
