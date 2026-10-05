class Solution {
public:
    int result = 0;
    int totalCellsToVisit = 0;

    bool isSafe(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void solve(int i, int j, vector<vector<int>>& grid, int m, int n, int visitedCount) {
        if (!isSafe(i, j, m, n) || grid[i][j] == -1) {
            return;
        }

        // Reached the destination (2)
        if (grid[i][j] == 2) {
            // Check if we visited all required cells (start + all 0s)
            if (visitedCount == totalCellsToVisit) {
                result++;
            }
            return;
        }

        // Mark cell as visited (-1 acting as barrier)
        int temp = grid[i][j];
        grid[i][j] = -1;

        // Explore all 4 directions (Down, Right, Up, Left)
        solve(i + 1, j, grid, m, n, visitedCount + 1); // Down
        solve(i, j + 1, grid, m, n, visitedCount + 1); // Right
        solve(i - 1, j, grid, m, n, visitedCount + 1); // Up
        solve(i, j - 1, grid, m, n, visitedCount + 1); // Left

        // Backtrack
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startX = 0, startY = 0;

        totalCellsToVisit = 0;
        result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) {
                    totalCellsToVisit++; // Count start (1), end (2), and empty cells (0)
                }
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }

        // Start recursion with visitedCount = 1 (counting the starting cell)
        solve(startX, startY, grid, m, n, 1);
        return result;
    }
};