class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if (a.empty()) return 0; 
        unordered_set<int> st(a.begin(), a.end());
        int longest = 1; 
        
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1; 
                int x = it; 
                
                
                while (st.find(x + 1) != st.end()) {
                    x = x + 1; 
                    cnt = cnt + 1; 
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};