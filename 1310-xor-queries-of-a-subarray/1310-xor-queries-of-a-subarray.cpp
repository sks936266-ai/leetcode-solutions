#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        int n = arr.size();
        
        // Step 1: Build the prefix XOR array
        // prefix[i] stores the XOR sum from arr[0] to arr[i-1]
        std::vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        // Step 2: Answer each query in O(1) time
        std::vector<int> result;
        result.reserve(queries.size());
        
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];
            // Using the property: (0 to R) ^ (0 to L-1) = (L to R)
            result.push_back(prefix[R + 1] ^ prefix[L]);
        }
        
        return result;
    }
};