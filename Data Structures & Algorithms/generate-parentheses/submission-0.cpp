class Solution {
public:
    void rec(vector<string>& res, string current, int open, int n) {
        if (current.size() >= n * 2) {
            if (open == 0) res.push_back(current);
            return;
        }

        rec(res, current + "(", open+1, n);
        if (open > 0) rec(res, current + ")", open-1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        rec(res, "", 0, n);
        return res;
    }
};
