class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a vector of pairs to keep track of the original indices
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort based on the values (the first element of the pair)
        sort(indexedNums.begin(), indexedNums.end());
        
        // Initialize left and right pointers
        int left = 0;
        int right = indexedNums.size() - 1;
        
        while (left < right) {
            int currentSum = indexedNums[left].first + indexedNums[right].first;
            
            if (currentSum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } 
            else if (currentSum < target) {
                left++; // Move left pointer right to increase the sum
            } 
            // currentSum > target
            else {
                right--; // Move right pointer left to decrease the sum
            }
        }
        
        return {}; // Fallback, though a solution is guaranteed
    }
};