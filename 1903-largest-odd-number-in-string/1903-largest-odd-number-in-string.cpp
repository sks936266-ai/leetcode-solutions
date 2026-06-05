class Solution {
public:
    string largestOddNumber(string num) {
        // Fix 1 & 2: Initialize 'i' to the last valid index (length - 1)
        for (int i = num.length() - 1; i >= 0; i--) {
            
            if ((num[i] - '0') % 2 != 0) {
                // Fix 3: Corrected spelling to 'substr'
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};