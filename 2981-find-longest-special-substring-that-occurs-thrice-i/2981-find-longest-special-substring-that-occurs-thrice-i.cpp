class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        // count[char_index][length] stores frequency
        vector<vector<int>> count(26, vector<int>(n + 1, 0));
        
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // Check if window breaks (next char differs) or we are at the end
            if (right == n - 1 || s[right] != s[right + 1]) {
                int len = right - left + 1;
                int charIdx = s[left] - 'a';
                
                // A block of length 'len' contributes to all sub-lengths
                for (int k = 1; k <= len; ++k) {
                    count[charIdx][k] += (len - k + 1);
                }
                
                // Move left to the start of the next block
                left = right + 1;
            }
        }
        
        int maxLen = -1;
        // Check all characters and lengths
        for (int i = 0; i < 26; ++i) {
            for (int len = n; len >= 1; --len) {
                if (count[i][len] >= 3) {
                    maxLen = max(maxLen, len);
                    break; // Optimization: found longest for this char
                }
            }
        }
        
        return maxLen;
    }
};