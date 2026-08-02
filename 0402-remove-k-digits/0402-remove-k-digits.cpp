class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }

        res = res.substr(start);

        return res.empty() ? "0" : res;
    }
};