class Solution {
    using P = pair<int, int>;

    int findXSum(const unordered_map<int, int>& mp, int x) {
        priority_queue<P, vector<P>, greater<P>> minHeap;

        for (auto const& [val, freq] : mp) {
            minHeap.push({freq, val});

            if (minHeap.size() > x) {
                minHeap.pop();
            }
        }

        int totalSum = 0;
        while (!minHeap.empty()) {
            auto [freq, val] = minHeap.top();
            minHeap.pop();
            totalSum += freq * val;
        }

        return totalSum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;

        int i = 0, j = 0;

        while (j < n) {
            mp[nums[j]]++;

            if (j - i + 1 == k) {
                result.push_back(findXSum(mp, x));

                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};