class Solution {
public:
    void rec(vector<int>& candidates, int i, int target, int curr_sum, vector<int> curr_sol, vector<vector<int>>& result, int prev_skipped) {
        if (curr_sum == target) {
            result.push_back(curr_sol);
            return;
        }

        if (curr_sum > target || i >= candidates.size()) {
            return;
        }

        rec(candidates, i+1, target, curr_sum, curr_sol, result, candidates[i]);
        if (candidates[i] != prev_skipped) {
            curr_sol.push_back(candidates[i]);
            curr_sum += candidates[i];
            rec(candidates, i+1, target, curr_sum, curr_sol, result, -1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr_sol;
        vector<vector<int>> result;
        rec(candidates, 0, target, 0, curr_sol, result, -1);
        return result;
    }
};
