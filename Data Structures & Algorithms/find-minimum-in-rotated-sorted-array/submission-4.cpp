class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] <= nums[r]) {
                return nums[l];
            }
            if (nums[r] <= nums[r - 1]) {
                return nums[r];
            }

            int m = (l + r) / 2;
            if (nums[m] < nums[m - 1]) {
                return nums[m];
            }

            if (nums[l] < nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            } 
        }
        return nums[l];
    }
};
