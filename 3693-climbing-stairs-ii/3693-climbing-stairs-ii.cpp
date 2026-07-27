class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int p1=0;
        if(n==0) return p1;
        int p2 = costs[0]+1;
        if(n==1) return p2;
        int p3 = min(costs[1]+4,p2+costs[1]+1);
        for(int i  = 2;i<n;i++){
            int temp = costs[i]+min({p1+9,p2+4,p3+1});
            p1 = p2;
            p2=p3;
            p3=temp;
        }
        return p3;
    }
};