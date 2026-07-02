class Solution {
public:
    int expandAroundcenter(const string&s,int left,int right){
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalcount=0;
        for(int center=0;center<s.length();center++){
            totalcount += expandAroundcenter(s,center,center);
            totalcount += expandAroundcenter(s,center,center+1);
        }
        return totalcount;
        
    }
};