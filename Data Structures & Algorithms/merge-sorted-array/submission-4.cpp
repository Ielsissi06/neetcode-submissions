class Solution {
public:
    vector<int> merger(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) return nums2;
        if (n == 0) return nums1;

        if (nums1[0] <= nums2[0]) {
            vector<int> tail(nums1.begin() + 1, nums1.end());
            vector<int> result = merger(tail, tail.size(), nums2, nums2.size());
            result.insert(result.begin(), nums1[0]);
            return result;
        } else {
            vector<int> tail(nums2.begin() + 1, nums2.end());
            vector<int> result = merger(nums1, nums1.size(), tail, tail.size());
            result.insert(result.begin(), nums2[0]);
            return result;
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m < nums1.size()) {
            nums1.erase(nums1.begin() + nums1.size() - 1);
        }
        while (n < nums2.size()) {
            nums2.erase(nums2.begin() + nums2.size() - 1);
        }

        nums1 = merger(nums1, m, nums2, n);
    }
};