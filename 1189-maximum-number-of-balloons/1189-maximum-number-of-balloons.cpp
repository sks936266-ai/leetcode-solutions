class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        for(char c:text){
            have[c]++;
        }
        unordered_map<char,int> need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        int res=INT_MAX;
        for(auto ch:need){
            char c=ch.first;
            int fneed=ch.second;
            int fhave=have[c];
            int times=fhave/fneed;
            res=min(res,times);
        }
        return res;
    }
};