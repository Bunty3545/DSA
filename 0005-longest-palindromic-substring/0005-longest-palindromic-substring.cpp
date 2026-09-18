
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 0;
        int n = s.length();
        for (int i = 0; i < n; ) {
            int left = i, right = i;
            while (right < n - 1 && s[right] == s[right + 1]) {
                right++;
            }
            i = right + 1;
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            int length = right - left + 1;
            if (length > maxLength) {
                start = left;
                maxLength = length;
            }
        }
        return s.substr(start, maxLength);
    }
};

