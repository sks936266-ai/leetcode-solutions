class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low=0,high=0;
        int maxlen=0;
        unordered_map<int,int>f;
        int n=fruits.size();
        for(high=0;high<n;high++){
            f[fruits[high]]++;
            while(f.size()>2){
                f[fruits[low]]--;
                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);
                }
                low++;
            }
            maxlen=max(maxlen,high-low+1);    
        }
        return maxlen;
    }
};