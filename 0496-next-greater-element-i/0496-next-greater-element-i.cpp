#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; // Diary: element -> uska next greater
        stack<int> st;              // Monotonic Stack
        
        // Step 1: nums2 par Striver wala logic chalao (Piche se loop)
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];
            
            // Pop: Chote bando ko stack se bahar pheko
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }
            
            // Store: Agar stack khali hai toh -1, nahi toh top waala hi answer hai
            if (st.empty()) {
                mp[current] = -1;
            } else {
                mp[current] = st.top();
            }
            
            // Push: Current bande ko stack me bitha do
            st.push(current);
        }
        
        // Step 2: nums1 ke liye answers map se nikaal kar final list banao
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]); // Direct map se answer uthaya O(1) me
        }
        
        return ans;
    }
};