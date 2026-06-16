class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string doubleds= s+s;
        return doubleds.find(goal)!=string::npos;
    }
};