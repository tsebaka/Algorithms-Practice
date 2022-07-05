class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {

            vector<int> nums_copy = nums;
            vector<int> ans(0);

            sort(nums.begin(), nums.end());
            int temp = nums[0] + nums[nums.size() - 1];
            int l = 0;
            int r = nums.size() - 1;
            bool flag = 0;
            bool flag_l = 0;
            bool flag_r = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (flag == 1) {
                    break;
                }

                if (temp < target) {
                    l += 1;
                    temp -= nums[l - 1];
                    temp += nums[l];
                } else { // 3 3
                    if (temp == target) {
                        flag = 1;

                        for (int j = 0; j < nums.size(); ++j) {

                            if (nums_copy[j] == nums[l] && flag_l == 0) {
                                l = j;
                                flag_l = 1;
                            } else {
                                if (nums_copy[j] == nums[r] && flag_r == 0) {
                                    r = j;
                                    flag_r = 1;
                                }
                            }
                        }

                        ans.push_back(l);
                        ans.push_back(r);
                    } else {
                        r -= 1;
                        temp -= nums[r + 1];
                        temp += nums[r];
                    }
                }
            }

            return ans;
        }
};
