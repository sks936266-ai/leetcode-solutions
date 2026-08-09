class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(char c:ransomNote){
            need[c]++;
        }
        for(char c:magazine){
            have[c]++;
        }
        for(auto pair:need){
            char ch=pair.first;
            int requiredcount=pair.second;
            if(have[ch]<requiredcount){
                return false;
            }
        }
        return true;
    }
};