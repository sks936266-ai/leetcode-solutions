class Solution {
public:
       
    void solve(int currnum,int n,vector<int> &result){
        if(currnum>n) return;
        result.push_back(currnum);
        for(int append=0;append<=9;append++){
            int newnum=(currnum*10)+append;
            if(newnum>n){
                return;
            }

            solve(newnum,n,result);
                
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int newnum=1;newnum<=9;newnum++){
            solve(newnum,n,result);
        }
        return result;
        
    }
    
};