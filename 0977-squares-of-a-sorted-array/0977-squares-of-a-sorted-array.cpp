#include <vector>
#include <cmath>

class Solution {
public:
std::vector<int> sortedSquares(std::vector<int>& nums) {
int n = nums.size();
std::vector<int> result(n);
int left = 0;
int right = n - 1;
for (int i = n - 1; i >= 0; --i) {
if (std::abs(nums[left]) > std::abs(nums[right])) {
result[i] = nums[left] * nums[left];
left++;
} else {
result[i] = nums[right] * nums[right];
right--;
}
}
return result;
}
};