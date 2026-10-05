class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for (int i = 0; i <= n; i++) { dp[i][0] = 1; }
        for (int i = 1; i <= n; i++) {
            int c = coins[i-1];
            for (int j = 1; j <= amount; j++) {
                int times = 0;
                if (j - c >= 0) {
                    times += dp[i][j-c];
                }
                dp[i][j] = dp[i-1][j] + times;
            }
        }
        return dp[n][amount];
    }
};
