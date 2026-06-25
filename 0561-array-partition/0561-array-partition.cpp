class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int totalsum=0;
        for(int i=0;i<nums.size();i+=2){
            totalsum+=nums[i];
        }
        return totalsum;
    }
};