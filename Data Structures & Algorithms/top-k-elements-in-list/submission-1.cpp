class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int n: nums) {
            if (freq_map.contains(n)) {
                freq_map[n]++;
            } else {
                freq_map[n] = 1;
            }
        }

        vector<pair<int, int>> f;
        for (pair<int, int> p: freq_map) {
            f.push_back(p);
        }
        sort(f.begin(), f.end(), [](pair<int, int>& l, pair<int, int>& r) { return l.second > r.second; });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(f[i].first);
        }
        return result;
    }
};
