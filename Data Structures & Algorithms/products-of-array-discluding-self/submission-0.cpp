class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int n_zeros = 0;
        int total_no_zeros = 1;
        for (int n: nums) {
            total *= n;
            if (n == 0) {
                n_zeros++;
            } else {
                total_no_zeros *= n;
            }
        }

        vector<int> result;
        for (int n: nums) {
            if (n != 0) {
                result.push_back(total / n);
            } else {
                result.push_back(n_zeros == 1 ? total_no_zeros : 0);
            }
        }
        return result;
    }
};
