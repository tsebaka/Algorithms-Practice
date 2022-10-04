#include <bits/stdc++.h>

using namespace std;

const unsigned long long p = 31;
const unsigned long long int m = 1e18;
unsigned long long int p_pow = 1;

int poly_hash (const string& str) {
    unsigned long long int h = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        h += ((str[i] - 'a' + 1) * p_pow) % m;
        p_pow *= p;
    }

    return h;
}

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    unsigned long long int hash1 = poly_hash(s1.substr(0, s2.size()));
    p_pow = 1;
    unsigned long long int hash2 = poly_hash(s2);
    p_pow = 1;
    vector<int> ans;
    long cnt = 0;

    for (size_t i = 0; i < s1.size() - s2.size() + 1; ++i) {
        if (hash1 == hash2) {
            if (s1.substr(i, s2.size()) == s2) {
                cnt += 1;
                ans.push_back(i + 1);
            }
        }
        p_pow = pow(p, s2.size());
        hash1 = (hash1 * p - (s1[i] - 'a' + 1) * p_pow + (s1[i + s2.size()] - 'a' + 1)) % m;
    }
    cout << cnt << "\n";
    for (auto i: ans) {
        cout << i << " ";
    }


    return 0;
}
