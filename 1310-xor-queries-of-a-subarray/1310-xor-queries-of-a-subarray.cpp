class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> cumXOR(n,0);
        cumXOR[0]=arr[0];
        for(int i=1;i<n;i++){
            cumXOR[i]=cumXOR[i-1]^arr[i];
        }
        vector<int> result;
        for(vector<int> query:queries){
            int L=query[0];
            int R=query[1];
            int XORvalue=cumXOR[R] ^ (L==0 ? 0:cumXOR[L-1]);
            result.push_back(XORvalue);
        }
        return result;
    }
};