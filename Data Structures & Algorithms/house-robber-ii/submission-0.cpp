class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp_first(n, 0), dp_last(n, 0);
        dp_first[0] = nums[0];
        dp_last[0] = 0;
        dp_first[1] = max(nums[1], nums[0]);
        dp_last[1] = nums[1];
        for (int i = 2; i < n-1; i++) {
            dp_first[i] = max(dp_first[i-1], nums[i] + dp_first[i-2]);
            dp_last[i] = max(dp_last[i-1], nums[i] + dp_last[i-2]);
        }
        dp_first[n-1] = dp_first[n-2];
        dp_last[n-1] = max(dp_last[n-2], nums[n-1] + dp_last[n-3]);
        return max(dp_first[n-1], dp_last[n-1]);
    }
};
