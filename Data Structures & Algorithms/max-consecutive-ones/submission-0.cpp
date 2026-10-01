class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, max_c = 0;
        for (int n: nums) {
            if (n == 0) {
                max_c = max(max_c, curr);
                curr = 0;
            } else {
                curr++;
            }
        }
        return max(curr, max_c);
    }
};