class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    if (count > max) max = count;
                    count = 1;
                    break;
                }
                count++;
            }
            if (count > max) max = count;
            count = 1;
            
        }
        return max;
    }
};