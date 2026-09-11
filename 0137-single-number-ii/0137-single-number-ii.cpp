class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int countones=0;
            for(int &num:nums){
                int temp=1<<k;
                if((num &temp)==0);
                else{
                    countones++;
                }
            }
            if(countones%3==1){
                result=(result|1<<k);
            }
        }
        return result;
    }
};