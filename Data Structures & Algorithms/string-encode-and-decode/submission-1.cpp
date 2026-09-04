class Solution {
public:

    string encode(vector<string>& strs) {
        string en;
        for (const string& s: strs) {
            char len = (char)s.length();
            en.push_back(len);
            en += s;
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> de;
        size_t i = 0;
        while (i < s.length()) {
            unsigned char len = (unsigned char)s[i];
            de.push_back(s.substr(i+1, len));
            i += 1 + len;
        }
        return de;
    }
};
