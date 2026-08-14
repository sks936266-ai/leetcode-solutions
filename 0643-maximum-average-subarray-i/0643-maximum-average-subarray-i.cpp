class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        if (n<k) return 0.0;
        int windowsum=0;
        for(int i=0;i<k;i++){
            windowsum+=nums[i];
        }
        int maxsum=windowsum;
        for(int i=k;i<n;i++){
            windowsum=windowsum-nums[i-k]+nums[i];
            if(windowsum>maxsum){
                maxsum=windowsum;
            }
        }
        return static_cast<double>(maxsum) / k;
    }
};