
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Hash set to store elements in the current window of size k
        unordered_set<int> window;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // If window size exceeds k, shrink from the left
            if (right - left > k) {
                window.erase(nums[left]);
                left++;
            }
            
            // Check if current element exists in the window
            if (window.count(nums[right])) {
                return true;
            }
            
            // Add current element to the window
            window.insert(nums[right]);
        }
        
        return false;
    }
};