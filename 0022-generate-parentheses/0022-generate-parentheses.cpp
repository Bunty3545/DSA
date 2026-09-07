#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};