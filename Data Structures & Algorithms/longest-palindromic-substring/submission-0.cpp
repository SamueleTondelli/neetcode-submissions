class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            int curr_start = i, curr_end = i;
            while (curr_start >= 0 && curr_end < s.size()) {
                if (s[curr_start] != s[curr_end]) break;
                curr_start--;
                curr_end++;
            }
            curr_start++;
            curr_end--;
            if (curr_end - curr_start + 1 > end - start + 1) {
                start = curr_start;
                end = curr_end;
            }

            curr_start = i;
            curr_end = i+1;
            while (curr_start >= 0 && curr_end < s.size()) {
                if (s[curr_start] != s[curr_end]) break;
                curr_start--;
                curr_end++;
            }
            curr_start++;
            curr_end--;
            if (curr_end - curr_start + 1 > end - start + 1) {
                start = curr_start;
                end = curr_end;
            }
        }

        string res = "";
        for (int i = start; i <= end; i++) {
            res += s[i];
        }
        return res;
    }
};
