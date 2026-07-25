class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int write=0;
        for(int read=0;read<nums.size();read++){
            if(nums[read]%2==0){
                int prev=nums[write];
                nums[write]=nums[read];
                nums[read]=prev;
                write++;
            }
        }
        return nums;
    }
};