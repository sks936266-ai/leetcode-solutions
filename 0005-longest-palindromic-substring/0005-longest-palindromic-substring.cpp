class Solution {
public:
    
    int expandAroundCenter(const string& s, int left, int right) {
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxlen = 1;
        
        
        for (int center = 0; center < s.length(); center++) {
            
            int len1 = expandAroundCenter(s, center, center);
            int len2 = expandAroundCenter(s, center, center + 1);
            int currentlen = max(len1, len2);

            if (currentlen > maxlen) {
                maxlen = currentlen;
                start = center - (currentlen - 1) / 2;
            }
        }
        return s.substr(start, maxlen);
    }
};