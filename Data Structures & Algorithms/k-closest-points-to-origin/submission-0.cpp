class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int>& l, vector<int>& r) -> bool { 
            return (sqrt(l[0]*l[0]+l[1]*l[1])) < (sqrt(r[0]*r[0]+r[1]*r[1]));
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q;
        for (const vector<int>& p: points) {
            q.push(p);
            if (q.size() > k) {
                q.pop();
            }
        }
        
        vector<vector<int>> res;
        for (; q.size() > 0; q.pop()) {
            res.push_back(q.top());
        }
        return res;
    }
};
