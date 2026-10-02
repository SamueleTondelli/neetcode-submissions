class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unique_nums;
        for (int n: nums) {
            unique_nums.insert(n);
        }

        int maxl = 0;
        for (int n: unique_nums) {
            if (!unique_nums.contains(n-1)) {
                int l = 1;
                for (; unique_nums.contains(n+l); l++);
                maxl = max(maxl, l);
            }
        }
        return maxl;
    }
};
