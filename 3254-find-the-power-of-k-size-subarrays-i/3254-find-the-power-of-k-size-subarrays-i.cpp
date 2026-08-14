class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return nums;

        vector<int> result;
        int count = 1;
        int i = 0, j = 0;

        while (j < n) {
            if (j > 0) {
                if (nums[j] == nums[j - 1] + 1) {
                    count++;
                } else {
                    count = 1;
                }
            }

            if (j - i + 1 == k) {
                if (count >= k) {
                    result.push_back(nums[j]);
                } else {
                    result.push_back(-1);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};