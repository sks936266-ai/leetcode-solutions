class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int left=0;
        int right=n-1;
        int index=n-1;
        while(left<=right){
            int leftval=abs(nums[left]);
            int rightval=abs(nums[right]);
            if(leftval>rightval){
                result[index]=leftval*leftval;
                left++;
            }
            else{
                result[index]=rightval*rightval;
                right--;
            }
            index--;
        }
        return result;
    }
};