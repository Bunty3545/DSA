class Solution {
    public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
        int l1 = expand(s, i, i);
        int l2 = expand(s, i, i + 1);
        int len = max(l1, l2);
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
            }
            }
            return s.substr(start, maxLen);
            }
            private:
            int expand(const string& s, int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            }
            return r - l - 1;
            }
            };                             
