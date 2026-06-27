class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long totalsum = 0;
        long long mod = 1e9 + 7;
        
        vector<int> pse(n, -1);
        stack<int> st1;
        for(int i = 0; i < n; i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){ 
                st1.pop();
            }
            if(!st1.empty()) pse[i] = st1.top();
            st1.push(i);
        }
        
        vector<int> nsee(n, n);
        stack<int> st2;
        for(int i = n - 1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){ 
                st2.pop();
            }
            if(!st2.empty()) nsee[i] = st2.top();
            st2.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            long long left_count = i - pse[i];
            long long right_count = nsee[i] - i;
            
            long long total_subarrays = (left_count * right_count) % mod;
            long long contribution = (total_subarrays * arr[i]) % mod;
            
            totalsum = (totalsum + contribution) % mod;
        }
        return totalsum;
    }
};