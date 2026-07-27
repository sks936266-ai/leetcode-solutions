class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        stack<char> st;
        for(char ch:s){
            if(ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty()&&st.top()=='['){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        int unmatched_closing=st.size()/2;
        return (unmatched_closing+1)/2;  
    }
};