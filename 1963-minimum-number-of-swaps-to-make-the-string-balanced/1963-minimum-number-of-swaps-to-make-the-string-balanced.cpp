class Solution {
public:
    int minSwaps(string s) {
        int unmatched = 0;

        for (char c : s) {
            if (c == '[') {
                unmatched++;
            } else {
                // Agar pehle se unmatched '[' maujood hai, toh match kar do
                if (unmatched > 0) {
                    unmatched--;
                }
            }
        }

        // Formula: ceil(unmatched / 2)
        return (unmatched + 1) / 2;
    }
};