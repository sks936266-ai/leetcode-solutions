class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        result[0] = findBound(nums, target, true);  // Find first
        if (result[0] == -1) return result;         // Target not found
        result[1] = findBound(nums, target, false); // Find last
        return result;
    }

private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int boundIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                boundIndex = mid;
                // If finding first, narrow search to left half
                if (isFirst) {
                    right = mid - 1;
                } 
                // If finding last, narrow search to right half
                else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return boundIndex;
    }
};