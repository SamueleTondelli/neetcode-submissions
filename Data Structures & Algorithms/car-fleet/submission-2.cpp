class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back(pair(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end(), [](pair<int, int>& l, pair<int, int>& r) { return l.first < r.first; });

        int n_fleets = 0;
        float curr_arrival = 0.0;
        for (int i = n-1; i >= 0; i--) {
            float arrival = (float)(target - cars[i].first) / cars[i].second;
            if (arrival > curr_arrival) {
                n_fleets++;
                curr_arrival = arrival;
            }
        }

        return n_fleets;
    }
};
