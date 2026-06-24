#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Base Case: Agar length odd hai, toh kabhi valid nahi ho sakta
        if (s.length() % 2 != 0) return false;
        
        stack<char> st;
        
        for (char c : s) {
            // 1. Agar opening brackets hain, toh unke CLOSING partners push karo
            if (c == '(') {
                st.push(')');
            } 
            else if (c == '[') {
                st.push(']');
            } 
            else if (c == '{') {
                st.push('}');
            }
            // 2. Agar closing bracket aaya hai
            else {
                // Pehle check karo stack khali toh nahi hai (e.g., s = "}")
                // Ya fir stack ka top current character se match nahi ho raha (e.g., s = "(]")
                if (st.empty() || st.top() != c) {
                    return false;
                }
                // Agar match ho gaya, toh chupchaap pop karo aur aage badho
                st.pop();
            }
        }
        
        // Aakhiri me agar stack khali hai, toh hi string valid hai
        return st.empty();
    }
};