class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
                int n = nums.size();
        int total_sum = 0;
        for (auto x: nums) total_sum += x;
        if (target > total_sum || target < -total_sum) return 0;

        vector<vector<int>> dp(n, vector<int>(total_sum*2 + 1, 0));
        dp[0][nums[0] + total_sum]++;
        dp[0][-nums[0] + total_sum]++;

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            for (int j = -total_sum; j <= total_sum; j++) {
                int offset = j + total_sum;
                if (dp[i-1][offset] > 0) {
                    dp[i][offset+curr] += dp[i-1][offset];
                    dp[i][offset-curr] += dp[i-1][offset];
                }
            }
        }

        return dp[n-1][target + total_sum];
    }
};
