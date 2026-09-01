// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            // Prevent integer overflow
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // Mid is bad; the first bad version is mid or to the left.
                right = mid;
            } else {
                // Mid is good; the first bad version is strictly to the right.
                left = mid + 1;
            }
        }
        
        // When left == right, we have found the first bad version.
        return left;
    }
};