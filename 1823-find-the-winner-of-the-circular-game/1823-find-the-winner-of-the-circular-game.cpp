class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;  // with 1 friend, the winner is at position 0

        for (int size = 2; size <= n; size++) {
            winner = (winner + k) % size;
        }

        return winner + 1;  // friends are numbered from 1
    }
};