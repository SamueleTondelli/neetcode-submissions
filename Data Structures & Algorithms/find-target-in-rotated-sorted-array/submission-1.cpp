class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le = 0, n = nums.size();
        for (; le < n; le++) {
            if (nums[le] > nums[(le+1)%n]) break;
        }

        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int pm = (m + le + 1) % n;
            if (nums[pm] == target) {
                return pm;
            } else if (nums[pm] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int pl = (l + le + 1) % n;
        return nums[pl] == target ? pl : -1;
    }
};
