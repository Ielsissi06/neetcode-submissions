class Solution {
public:
    int rob(vector<int>& nums) {
        // 1D DP of size nums.size()
        // Each cell i represents the maximum ammount you can rob at cell i
        // DP[0] = nums[0];
        // DP[1] = max(nums[0], nums[1])
        // DP[i] = max(DP[i-2], DP[i-1])
        // return DP[nums.size()-1]

        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> DP(nums.size());
        DP[0] = nums[0];
        DP[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            DP[i] = max(DP[i-2] + nums[i], DP[i-1]);
        }

        return DP[nums.size() - 1];
    }
};
