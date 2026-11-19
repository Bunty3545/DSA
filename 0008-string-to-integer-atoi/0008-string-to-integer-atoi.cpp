class Solution {
    public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > (2147483647 - digit) / 10) {
                if (sign == 1) {
                    return 2147483647;
                } else {
                    return -2147483648;
                    }
                    }
                    result = result * 10 + digit;
                    i++;
                    }
                    return (int)(sign * result);
                    }
                    };                              
