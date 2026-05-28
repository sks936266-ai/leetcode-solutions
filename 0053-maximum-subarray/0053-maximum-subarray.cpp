#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Base case: if the vector has only one element, return it
        int max_global = nums[0];
        int current_sum = nums[0];
        
        // Traverse the array starting from the second element
        for (size_t i = 1; i < nums.size(); ++i) {
            // Decide whether to add the current element to the existing subarray 
            // or start a completely new subarray from this element
            current_sum = max(nums[i], current_sum + nums[i]);
            
            // Update the global maximum if the current subarray sum is greater
            if (current_sum > max_global) {
                max_global = current_sum;
            }
        }
        
        return max_global;
    }
};