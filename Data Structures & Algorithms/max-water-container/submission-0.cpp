class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int lh = heights[l], rh = heights[r];
            max_area = max(max_area, min(lh, rh) * (r - l));
            if (lh < rh) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};
