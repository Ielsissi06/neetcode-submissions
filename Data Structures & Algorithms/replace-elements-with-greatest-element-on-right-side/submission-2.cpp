class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans = arr;
        int right_max = -1;

        for (int i = arr.size()-1; i >= 0; i--) {
            ans[i] = right_max;
            right_max = max(arr[i], right_max);
        }

        return ans;
    }
};