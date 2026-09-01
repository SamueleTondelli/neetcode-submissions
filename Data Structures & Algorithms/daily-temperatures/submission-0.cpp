class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for (auto i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!s.empty() && s.top().first < t) {
                int j = s.top().second;
                result[j] = i - j;
                s.pop();
            }
            s.push({t, i});
        }
        return result;
    }
};
