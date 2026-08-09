class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(char c:s){
            f[c]++;
        }
        bool odd=false;
        int res=0;
        for(auto ch:f){
            int val=ch.second;
            if(val%2==0){
                res+=val;
            }
            else{
                odd=true;
            }
        }
        if(odd==false){
            return res;
        }
        for(auto ch:f){
            int val=ch.second;
            if(val%2==1){
                res+=val-1;
            }
        }
        return res+1;
    }
};