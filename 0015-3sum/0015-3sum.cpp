class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for (int j = 0; j < n - 2; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) {
                continue;
            }
            
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = nums[j] + nums[left] + nums[right];
                
                if (total == 0) {
                    result.push_back({nums[j], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                } 
                else if (total < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return result;
    }
};