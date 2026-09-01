class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2) return 0;

        int buy = 0, sell = 1;
        int maxp = 0;
        while (sell < size) {
            int p = prices[sell] - prices[buy];
            if (p > 0) {
                maxp = max(maxp, p);
            } else {
                buy = sell;
            }
            sell++;
        }
        return maxp;
    }
};
