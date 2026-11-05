class Solution {
public:
    vector<int> countBits(int n) {
        // DP is a 1D array of size n+1
        // Each cell i represents numbits for the number i
        // DP[0] = 0
        // DP[1] = 1
        // DP[i] = DP[i/2] + i%2

        vector<int> DP(n+1);
        DP[0] = 0;
        if (n == 0) return DP;
        DP[1] = 1;
        

        for (int i = 2; i < n+1; i++) {
            DP[i] = DP[i/2] + i%2;
        }

        return DP;
    }
};
