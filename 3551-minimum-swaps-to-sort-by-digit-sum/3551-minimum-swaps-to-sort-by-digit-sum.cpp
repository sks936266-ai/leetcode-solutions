class Solution {
public:
    int digitsum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
       int n=nums.size();
       vector<int> aftersorted(nums);
       auto lamda=[&](int num1,int num2){
        int num1digit=digitsum(num1);
        int num2digit=digitsum(num2);
        if(num1digit!=num2digit){
            return num1digit<num2digit;
        }
        return num1<num2;
       };
       sort(begin(aftersorted),end(aftersorted),lamda);
       unordered_map<int,int>validx;
       for(int i=0;i<n;i++){
        validx[nums[i]]=i;
       }
       int swapcount=0;
       for(int i=0;i<n;i++){
        int expectedval=aftersorted[i];
        int currval=nums[i];
        if(expectedval==currval) continue;
        int idx=validx[expectedval];
        nums[i]=expectedval;
        nums[idx]=currval;
        validx[expectedval]=i;
        validx[currval]=idx;
        swapcount++;
       }
       return swapcount;

    }
};