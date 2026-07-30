class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        std::vector<int> stack;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // While stack is not empty, current val is smaller than top,
            // and we have enough remaining elements to fill the stack to size k
            while (!stack.empty() && nums[i] < stack.back() && 
                   stack.size() + (n - i) > k) {
                stack.pop_back();
            }
            
            // Only push if we haven't filled the required length k
            if (stack.size() < k) {
                stack.push_back(nums[i]);
            }
        }
        
        return stack;
    }
};