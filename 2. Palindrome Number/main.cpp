class Solution {
    public:
        bool isPalindrome(int x) {
            string s = to_string(x);

            if (s.size() == 1) {
                return true;
            } else {
                int l = 0;
                int r = s.size() - 1;
                bool flag = 0;

                if (s.size() % 2 != 0) {
                    while (l != r + 2) {
                        if (s[l] != s[r]) {
                            flag = 1;
                            break;
                        }

                        l += 1;
                        r -= 1;
                    }
                } else {
                    while (l != r + 1) {
                        if (s[l] != s[r]) {
                            flag = 1;
                            break;
                        }

                        l += 1;
                        r -= 1;
                    }
                }

                if (flag == 0) {
                    return true;
                } else {
                    return false;
                }
            }

        }
};
