class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int l = 0, r = rows * cols - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int i = m / cols;
            int j = m % cols;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};
