class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int lo = 0;
        int hi = ROWS * COLS - 1;

        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            int row = mid / COLS;
            int col = mid % COLS;

            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) hi = mid - 1;
            else lo = mid + 1;
        }

        return false;
    }
};
