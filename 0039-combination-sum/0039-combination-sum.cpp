class Solution {
private:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result){
        if(target==0){
            result.push_back(current);
            return;
        }
        if(target <0 || idx==candidates.size()){
            return;
        }
        current.push_back(candidates[idx]);
        solve(idx,candidates,target-candidates[idx],current,result);
        current.pop_back();

        solve(idx+1,candidates,target,current,result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int> current;
        solve(0,candidates,target,current,result);
        return result;
    }
};