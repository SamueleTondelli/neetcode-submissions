class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int start = i, end = i;
            while (start >= 0 && end < s.size()) {
                if (s[start] != s[end]) break;
                res++;
                start--;
                end++;
            }

            start = i;
            end = i+1;
            while (start >= 0 && end < s.size()) {
                if (s[start] != s[end]) break;
                res++;
                start--;
                end++;
            }
        }
        return res;
    }
};
