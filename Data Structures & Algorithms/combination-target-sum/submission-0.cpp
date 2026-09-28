class Solution {
public:
    void rec(vector<int>& nums, vector<int> curr, vector<vector<int>>& result, int target, int i, int curr_sum) {
        if (curr_sum == target) {
            result.push_back(curr);
            return;
        } else if (curr_sum > target) {
            return;
        }

        if (i >= nums.size()) {
            return;
        }

        int freq = 0;
        while (curr_sum + freq * nums[i] <= target) {
            rec(nums, curr, result, target, i+1, curr_sum + freq*nums[i]);
            curr.push_back(nums[i]);
            freq++;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> result;
        rec(nums, curr, result, target, 0, 0);
        return result;
    }
};
