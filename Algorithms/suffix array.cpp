#include <iostream>
#include <cstring>

const int maxlen = 400002;
const int alphabet = 126;

int main() {

	std::string s;
	std::cin >> s;
	s = s + "$";

	int len = s.size();

	// 0-phase

	int cnt[maxlen];
	int suff_array[maxlen];
	std::memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < len; ++i)
		cnt[s[i]] += 1;
	for (int i = 1; i <= alphabet; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = len - 1; i >= 0; --i) {
		cnt[s[i]] -= 1;
		suff_array[cnt[s[i]]] = i;
	}

	int classes_arr[maxlen];
	int classes = 1;
	for (int i = 1; i < len; ++i) {
		if (s[suff_array[i]] != s[suff_array[i - 1]])
			classes += 1;
		classes_arr[suff_array[i]] = classes - 1;
	}

	// every k-phase

	int temp_suff_array[maxlen];
	int temp_classes_arr[maxlen];
	for (int k = 0; (1 << k) < len; ++k) {
		for (int i = 0; i < len; ++i) {
			temp_suff_array[i] = suff_array[i] - (1 << k);
			if (temp_suff_array[i] < 0)
				temp_suff_array[i] += len;
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < len; ++i)
			cnt[classes_arr[temp_suff_array[i]]] += 1;
		for (int i = 1; i < classes; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = len - 1; i >= 0; --i) {
			cnt[classes_arr[temp_suff_array[i]]] -= 1;
			suff_array[cnt[classes_arr[temp_suff_array[i]]]] = temp_suff_array[i];
		}

		temp_classes_arr[suff_array[0]] = 0;
		classes = 1;
		int right_part_1;
		int right_part_2;
		for (int i = 1; i < len; ++i) {
			right_part_1 = (suff_array[i] + (1 << k)) % len;
			right_part_2 = (suff_array[i - 1] + (1 << k)) % len;
			if (classes_arr[suff_array[i]] != classes_arr[suff_array[i - 1]] or
			        classes_arr[right_part_1] != classes_arr[right_part_2])
				classes += 1;
			temp_classes_arr[suff_array[i]] = classes - 1;

		}
		std::memcpy(classes_arr, temp_classes_arr, sizeof(temp_classes_arr));
	}

	for (int i = 1; i < len; ++i)
		std::cout << suff_array[i] + 1 << " ";
}