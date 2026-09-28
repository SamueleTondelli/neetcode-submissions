class Solution {
public:
    void rec(vector<int>& nums, vector<int> curr, vector<vector<int>>& result, int iter) {
        if (iter >= nums.size()) {
            result.push_back(curr);
            return;
        }
        rec(nums, curr, result, iter+1);
        curr.push_back(nums[iter]);
        rec(nums, curr, result, iter+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        rec(nums, curr, result, 0);
        return result;
    }
};
