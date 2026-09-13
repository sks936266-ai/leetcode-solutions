class Solution {
public:
    int hammingWeight(int n) {
        int countonebits=0;
        countonebits+=__builtin_popcount(n);
        return countonebits;
    }
    
};