#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; 
        stack<int> st;              
        
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];
            
            
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }
            
            
            if (st.empty()) {
                mp[current] = -1;
            } else {
                mp[current] = st.top();
            }
            
            
            st.push(current);
        }
        
        
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]); 
        }
        
        return ans;
    }
};