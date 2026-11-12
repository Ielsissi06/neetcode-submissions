class Solution {
public:
    bool works(vector<int> piles, int h, int k) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1LL) / k;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int mid;

        while (lo <= hi) {
            mid = lo + (hi-lo) / 2;
            if (works(piles, h, mid)) hi = mid - 1;
            else lo = mid + 1;
        }

        return hi + 1;
    }
};
