class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> smashed(stones.begin(), stones.end());
        while (smashed.size() > 1) {
            int s1 = smashed.top();
            smashed.pop();
            int s2 = smashed.top();
            smashed.pop();
            if (s1 > s2) {
                smashed.push(s1 - s2);
            }
        }

        return smashed.size() == 1 ? smashed.top() : 0;
    }
};
