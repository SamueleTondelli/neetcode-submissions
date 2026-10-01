class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        unordered_map<char, int> pos;
        for (char c: s) {
            pos[c] = -1;
        }

        int max_len = 1;
        int start = 0;
        int end = 0;
        for (; end < s.size(); end++) {
            int curr_len = end - start + 1;
            char c = s[end];
            if (pos[c] < start || curr_len == 1) {
                pos[c] = end;
            } else {
                max_len = max(max_len, curr_len - 1);
                start = pos[c] + 1;
                pos[c] = end;
            }
        }

        return max(max_len, end - start);
    }
};
