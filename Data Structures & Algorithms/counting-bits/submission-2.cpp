class Solution {
public:
    vector<int> countBits(int n) {
        // DP is a 1D array of size n+1
        // Each cell i represents numbits for the number i
        // DP[0] = 0
        // DP[1] = 1
        // DP[i] = DP[i/2] + i%2

        vector<int> DP(n+1);

        for (int i = 1; i < n+1; i++) {
            DP[i] = DP[i/2] + i%2;
        }

        return DP;
    }
};
