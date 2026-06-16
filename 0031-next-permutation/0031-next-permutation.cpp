class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        
        // Step 1: Peeche se break-point dundho
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        
        // Step 2: Agar koi break-point nahi mila, toh reverse karke return kar jao
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return; // Semicolon standard aur break ki jagah return
        }
        
        // Step 3: Peeche se index wale element se just bada element dundho aur swap karo
        for(int i = n - 1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[index], nums[i]);
                break;
            }
        }
        
        // Step 4: Index ke baad wale saare elements ko reverse kar do
        reverse(nums.begin() + index + 1, nums.end());
    }
};