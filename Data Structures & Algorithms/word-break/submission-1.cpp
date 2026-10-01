class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int dsize = wordDict.size();
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < dsize; j++) {
                int wlen = wordDict[j].size();
                int start = i - wlen;
                if (start >= 0) {
                    if (s.substr(start, wlen) == wordDict[j] && dp[start]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
