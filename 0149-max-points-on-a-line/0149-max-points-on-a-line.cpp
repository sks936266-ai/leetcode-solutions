class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int max_overall = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slope_count;
            int current_max = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Reduce dy and dx by their GCD to avoid precision issues
                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Standardize negative signs so (dy, dx) and (-dy, -dx) match
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    // Vertical line: normalize dy to 1
                    dy = 1;
                }

                string key = to_string(dy) + "/" + to_string(dx);
                slope_count[key]++;
                current_max = max(current_max, slope_count[key]);
            }

            // Include the anchor point itself (+1)
            max_overall = max(max_overall, current_max + 1);
        }

        return max_overall;
    }
};