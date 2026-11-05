class Solution {
public:
    int climbStairs(int n) {
        // 1D DP of size n. 
        // Cell i represents the number of ways to get to cell i.
        // Base case DP[0] = 1, DP[1] = 2
        // DP[i] = DP[i-1] + DP[i-2]
        // Return DP[n-1]

        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> DP(n);
        DP[0] = 1;
        DP[1] = 2;
        
        for (int i = 2; i < n; i++) {
            DP[i] = DP[i-1] + DP[i-2];
        }
        return DP[n-1];
    }
};
