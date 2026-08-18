class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // 1. Ek naya khali vector banaya answer store karne ke liye
        vector<int> ans;
        
        // 2. Memory optimization: Humko pata hai total elements 2*n honge
        // Isliye advance me train ki bogeys book kar li!
        ans.reserve(2 * n);
        
        // 3. Loop chalaya n tak (kyunki x elements 0 se n-1 tak hain)
        for(int i = 0; i < n; i++) {
            
            // Pehle 'x' wala element daala
            ans.push_back(nums[i]);
            
            // Fir turant uske joda 'y' wala element daala
            ans.push_back(nums[i + n]);
        }
        
        // 4. Result return kar diya
        return ans;
    }
};