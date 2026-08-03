#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
    int solve(int i, int j, vector<int>& nums) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return nums[i];
        }

        // If P1 takes nums[i], P2 will force P1 to get the MINIMUM of next moves
        int take_i = nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));

        // If P1 takes nums[j], P2 will force P1 to get the MINIMUM of next moves
        int take_j = nums[j] + min(solve(i, j - 2, nums), solve(i + 1, j - 1, nums));

        return max(take_i, take_j);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(begin(nums), end(nums), 0);
        
        int player1_score = solve(0, n - 1, nums);
        int player2_score = total_score - player1_score; // Fixed typo here

        return player1_score >= player2_score; // Added return condition
    }
};