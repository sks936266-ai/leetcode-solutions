class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write=0;
        for(int r=0 ;r< nums.size();r++){
            if(nums[r]!=0){
                nums[write]=nums[r];
                write++;
            }
        }
        while(write<nums.size()){
            nums[write]=0;
            write++;
        }
    }
};