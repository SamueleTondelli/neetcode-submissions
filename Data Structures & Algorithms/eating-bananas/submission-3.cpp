class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = 0;
        for (int p: piles) {
            m = std::max(m, p);
        }

        int r = m;
        int l = 1;
        int k;
        while (l <= r) {
            k = (l + r) / 2;
            if (k == 1) break;
            unsigned long long hours = 0, hours_slower = 0;
            for (int p: piles) {
                hours += (p + k - 1) / k;
                hours_slower += (p + k - 2) / (k - 1);
            }
            if (hours <= h && hours_slower > h) {
                break;
            } else if (hours_slower <= h) {
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return k;
    }
};
