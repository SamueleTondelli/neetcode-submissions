class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        int i = 0;
        while (i < n) {
            int target = -nums[i];
            
            int l = i+1, r = n-1;
            while (l < r) {
                int nl = nums[l];
                int nr = nums[r];
                int s = nums[l] + nums[r];
                if (s == target) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    do {
                        l++;
                    } while (l < r && nums[l] == nl);
                } else if (s < target) {
                    l++;
                } else {
                    r--;
                }
            }
            
            do {
                i++;
            } while (i < n && nums[i] == -target);
        }

        return result;
    }
};
