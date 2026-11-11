class Solution {
public:
    void search(vector<vector<int>>& heights, vector<vector<bool>>& seen, int i, int j, bool& atl, bool& pac) {
        if (atl && pac || seen[i][j]) {
            return;
        }

        seen[i][j] = true;
        int n = heights.size();
        int m = heights[0].size();
        if (i == 0 || j == 0) {
            pac = true;
        }

        if (i == (n-1) || j == (m-1)) {
            atl = true;
        }

        if (i > 0 && heights[i][j] >= heights[i-1][j]) search(heights, seen, i-1, j, atl, pac);
        if (i < n-1 && heights[i][j] >= heights[i+1][j]) search(heights, seen, i+1, j, atl, pac);
        if (j > 0 && heights[i][j] >= heights[i][j-1]) search(heights, seen, i, j-1, atl, pac);
        if (j < m-1 && heights[i][j] >= heights[i][j+1]) search(heights, seen, i, j+1, atl, pac);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool atl = false, pac = false;
                vector<vector<bool>> seen(n, vector<bool>(m, false));
                search(heights, seen, i, j, atl, pac);
                if (atl && pac) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};

