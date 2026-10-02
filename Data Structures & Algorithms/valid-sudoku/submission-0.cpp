class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // rows
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (char c: board[i]) {
                if (c == '.') continue;
                if (seen.contains(c)) return false;
                seen.insert(c);
            }
        }
        // cols
        for (int j = 0; j < n; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < n; i++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (seen.contains(c)) return false;
                seen.insert(c);
            }
        }

        // sub-boxes
        for (int bi = 0; bi < n/3; bi++) {
            for (int bj = 0; bj < n/3; bj++) {
                unordered_set<char> seen;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[bi*3 + i][bj*3 + j];
                        if (c == '.') continue;
                        if (seen.contains(c)) return false;
                        seen.insert(c);
                    }
                }
            }
        }

        return true;
    }
};
