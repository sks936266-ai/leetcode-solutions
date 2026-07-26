class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int add_needed = 0;

        for (char c : s) {
            if (c == '(') {
                open_needed++;
            } else { // c == ')'
                if (open_needed > 0) {
                    open_needed--; // Valid pair ban gaya
                } else {
                    add_needed++; // Bhaagte hue ')' ke liye ek '(' chahiye
                }
            }
        }

        // Remaining unmatched '(' + unmatched ')'
        return open_needed + add_needed;
    }
};