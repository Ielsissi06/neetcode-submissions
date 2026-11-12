class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3);
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        int n = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < counts[i]; j++) {
                    nums[n] = i;
                    n++;
            }
        }

        return;
    }
};