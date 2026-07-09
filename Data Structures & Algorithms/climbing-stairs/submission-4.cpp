class Solution {
private:
    unordered_map<int, int> ways{{1, 1}, {2,2}};
public:
    int climbStairs(int n) {
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
