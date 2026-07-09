class Solution {
private:
    unordered_map<int, int> ways{{1, 1}, {2, 2}};
public:
    int climbStairs(int n) {
        if (ways.count(n)) {
            return ways[n];
        }
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        ways[n] = result;   // each call caches its own result
        return result;
    }
};