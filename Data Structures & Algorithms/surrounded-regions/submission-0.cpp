class Solution {
public:
    void search(vector<vector<char>>& board, vector<vector<bool>>& seen, int i, int j, bool& border) {
        if (seen[i][j]) return;

        int n = board.size();
        int m = board[0].size();
        if (i == 0 || i == n-1 || j == 0 || j == m-1) {
            border = true;
            return;
        }

        if (border) return;

        seen[i][j] = true;
        if (i > 0 && board[i-1][j] == 'O') search(board, seen, i-1, j, border);
        if (i < n-1 && board[i+1][j] == 'O') search(board, seen, i+1, j, border);
        if (j > 0 && board[i][j-1] == 'O') search(board, seen, i, j-1, border);
        if (j < m-1 && board[i][j+1] == 'O') search(board, seen, i, j+1, border);
    }

    void replace(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'X';
        int n = board.size();
        int m = board[0].size();
        if (i > 0 && board[i-1][j] == 'O') replace(board, i-1, j);
        if (i < n-1 && board[i+1][j] == 'O') replace(board, i+1, j);
        if (j > 0 && board[i][j-1] == 'O') replace(board, i, j-1);
        if (j < m-1 && board[i][j+1] == 'O') replace(board, i, j+1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    vector<vector<bool>> seen(n, vector<bool>(m, false));
                    bool border = false;
                    search(board, seen, i, j, border);
                    if (!border) {
                        replace(board, i, j);
                    }
                }
            }
        }
    }
};
