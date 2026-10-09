class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int count = 0;
        for (int x : nums) {
            for (int y : nums) {
                if (x == y) count++;
            }
            if (count > 1) return true;
            count = 0;
        }
        return false;
    }
};