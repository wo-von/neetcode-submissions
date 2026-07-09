class Solution {
private:
    unordered_map<int, int> ways;
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (ways.contains(n)){
            return ways[n];
        }
        int prev = climbStairs(n - 2); 
        int prevprev = climbStairs(n - 1);
        if (!ways.contains(n-1))
            ways[n-2] = prev;
        if (!ways.contains(n-2))
            ways[n-2] = prevprev;
        return prev + prevprev;
    }
};
