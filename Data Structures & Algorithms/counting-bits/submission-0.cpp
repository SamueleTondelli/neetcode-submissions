class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            int x = 0;
            int num = i;
            for (int j = 0; j < 10; j++) {
                x += (num & 1);
                num = num >> 1;
            }
            res.push_back(x);
        }
        return res;
    }
};
