class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count1 = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                count1++;
            }
        }
        
        if(count1 > 0) {
            return n - count1;
        }
        
        int minStepsTo1 = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            int GCD = nums[i];
            for(int j = i + 1; j < n; j++) {
                GCD = std::gcd(GCD, nums[j]);
                
                if(GCD == 1) {
                    minStepsTo1 = min(minStepsTo1, j - i);
                    break;
                }
            }
        }
        
        if(minStepsTo1 == INT_MAX) {
            return -1;
        }
        
        return minStepsTo1 + (n - 1);
    }
};