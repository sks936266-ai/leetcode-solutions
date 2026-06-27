class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int current=nums[i%n];
            int index=i%n;
            while(!st.empty()&& st.top() <=current){
                st.pop();
            }
            if(st.empty()){
                ans[i%n]=-1;
            }
            else{
                ans[i%n]=st.top();
            }
            st.push(current);
        }
        return ans;
    }
     
};