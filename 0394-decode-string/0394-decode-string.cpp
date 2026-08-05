class Solution {
public:
    string decodeString(string s) {
        stack<int> countstack;
        stack<string> stringstack;
        string currentstring="";
        int k=0;
        for(char ch:s){
            if(isdigit (ch)){
                k=k*10+(ch-'0');
            }else if(ch=='['){
                countstack.push(k);
                stringstack.push(currentstring);
                currentstring="";
                k=0;
            } else if(ch==']'){
                string decodedstring=stringstack.top();
                stringstack.pop();
                int currentK = countstack.top();
                countstack.pop();
                for(int i=0;i<currentK;i++){
                    decodedstring +=currentstring;
                }
                currentstring = decodedstring;
            }else{
                currentstring+=ch;
            }
        }
        return currentstring;
    }
};