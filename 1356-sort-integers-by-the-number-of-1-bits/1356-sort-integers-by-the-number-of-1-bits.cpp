class Solution {
public:
    int countonebits(int num){
        int count=0;
        while(num!=0){
            count+=(num&1);
            num>>=1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto lamda=[this](int &a,int &b){
            int count_a=countonebits(a);
            int count_b=countonebits(b);
            if(count_a==count_b){
                return a<b;
            }
            return count_a < count_b;
        };
        sort(begin(arr),end(arr),lamda);
        return arr;
    }
};